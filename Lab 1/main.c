#include <stdio.h>
#include <string.h>

int lineCounter() {
    int current = 0;
    int counter = 1;
    while (current != EOF) {
        current = getchar();
        if (current == '\n') {
            counter++;
        }
    }
    return counter;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Wrong number of arguments");
    } else {
        if (freopen(argv[2], "r", stdin) != NULL) {
            if (!strcmp(argv[1], "-l") || !strcmp(argv[1], "--lines")) {
                printf("%d", lineCounter());
            } else {
                printf("Invalid command");
            }
        } else {
            printf("Incorrect file name");
        }
    }
    return 0;
}
