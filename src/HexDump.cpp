//
// Created by wolverindev on 22.04.17.
//

#include "HexDump.h"
#include <sstream>
#include <iomanip>

using namespace std;
namespace Dump {
    namespace Hex {
        void dump (void *addr, int len, int pad, void (*print)(char*)) {
            int i;
            unsigned char buff[pad+1];
            unsigned char *pc = (unsigned char*)addr;

            if (len <= 0) {
                return;
            }

            stringstream line;
            line << uppercase << hex << setfill('0');
            // Process every byte in the data.
            for (i = 0; i < len; i++) {
                // Multiple of 16 means new line (with line offset).

                if ((i % pad) == 0) {
                    // Just don't print ASCII for the zeroth line.
                    if (i != 0)
                        line << buff << endl;

                    // Output the offset.
                    line << setw(4) << i << "    ";
                }
                if(i % 8 == 0 && i % pad != 0){
                    line << "| ";
                }

                // Now the hex code for the specific character.
                line << setw(2) << (int) pc[i] << " ";

                // And store a printable ASCII character for later.
                if ((pc[i] < 0x20) || (pc[i] > 0x7e))
                    buff[i % pad] = '.';
                else
                    buff[i % pad] = pc[i];
                buff[(i % pad) + 1] = '\0';
            }

            // Pad out last line if not exactly 16 characters.
            while ((i % pad) != 0) {
                line << "   ";
                if(i % 8 == 0 && i % pad != 0) line << "  "; //The mid delimiter
                i++;
            }

            line << buff << endl;
            print(line.str().c_str());
        }
    }
}
