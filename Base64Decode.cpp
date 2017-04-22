#include <iostream>
#include "src/Base64Utils.h"
#include "src/HexDump.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <cstring>

int main(int argc, char **argv)
{
    int c;
    int digit_optind = 0;

    bool printBinary = false;
    int binaryWhidth = 16;

    while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        static struct option long_options[] = {
                {"printBinary", optional_argument, 0,  0 },
                {"help", no_argument, 0,  0 }
        };

        c = getopt_long(argc, argv, "bb:h", long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
            case 0:
                if(strcmp(long_options[option_index].name, "printBinary") == 0){
                    printBinary = true;
                    if(optarg)
                        binaryWhidth = atoi(optarg);
                    break;
                } else if(strcmp(long_options[option_index].name, "help") == 0){
                    printf("Base64-Decode [-b | -b=<width> | -printBinary | -printBinary=<width>] <base64>...\n");
                    return 0;
                }
            case 'b':
                printBinary = true;
                if(optarg)
                    binaryWhidth = atoi(optarg);
                break;
            case 'h':
                printf("Base64-Decode [-b | -b=<width> | -printBinary | -printBinary=<width>] <base64>...\n");
                return 0;
            default:
                printf("Invalid argument '%d'\n", c);
                return 1;
        }
    }

    if(binaryWhidth % 8 != 0){
        printf("Invalid binary width!\n");
        return 2;
    }

    if (optind < argc) {
        while (optind < argc){
            std::string out = base64_decode(argv[optind++]);
            if(printBinary){
                Dump::Hex::dump((void*) out.c_str(), out.length(), binaryWhidth);
            } else {
                printf("%s\n", out.c_str());
            }
        }
    }
}