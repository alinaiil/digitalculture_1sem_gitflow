#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Wrong number of arguments");
    } else {
        if (freopen(argv[2], "r", stdin) != NULL) {
            
        } else {
            printf("Incorrect file name");
        }
    }
    return 0;
}
