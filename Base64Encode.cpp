#include <iostream>
#include <cstring>
#include "src/Base64Utils.h"

using namespace std;
int main(int argc, char **argv)
{
    if(argc <= 1){
        printf("Invalid argument count!");
        printf("base64-encode <text/data>");
        return 0;
    }
    for(int i = 1;i < argc; i++){
        cout << base64_encode(argv[i], strlen(argv[i])) << endl;
    }
}