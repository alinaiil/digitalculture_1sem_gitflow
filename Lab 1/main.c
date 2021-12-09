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

int byteCounter() {
    int counter = 0;
    while (1) {
        int current = getchar();
        if (current == EOF) {
            break;
        }
        counter++;
        if (current == '\n') {
            counter++;
        }
    }
    return counter;
}

int isWhitespace(int symbol) {
    if (symbol == '\t' || symbol == '\n' || symbol == ' ' ||
        symbol == '\v' || symbol == '\f' || symbol == '\r') {
        return 1;
    }
    return 0;
}

int wordCounter() {
    int current = 0;
    int counter = 0;
    int wordFlag = 0;
    while (current != EOF) {
        current = getchar();
        if (wordFlag && (isWhitespace(current) || current == EOF)) {
            counter++;
            wordFlag = 0;
        } else if (!isWhitespace(current)) {
            wordFlag = 1;
        }
    }
    return counter;
}

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
