#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int base = 1000000000;

typedef struct {
    int value[35];
} uint1024_t;

void scanf_value(uint1024_t *x, char val[]) {
    int length = strlen(val);
    //printf("Length: %d\n", length);
    int needed = length / 9 + (length % 9 ? 1 : 0);
    //printf("Needed: %d\n", needed);
    for (int i = 0; i < 35 - needed; i++) {
        x->value[i] = -1 * base;
    }
    int numbers = length % 9 + (!(length % 9) ? 9 : 0);
    //printf("Numbers: %d\n", numbers);
    put_digit(x, val, numbers, 35 - needed, 0);
    int counter = 0;
    for (int i = 36 - needed; i < 35; i++) {
        put_digit(x, val, 9, i, numbers + (counter * 9));
        counter++;
    }
}

int main(int argc, char *argv[]) {
    uint1024_t a, b, c;
    unsigned int ui = 123456789;
    scanf_value(&a, argv[1]);
    scanf_value(&b, argv[2]);

    printf("First number is: ");
    printf_value(a);
    printf(".\n");

    printf("Second number is: ");
    printf_value(b);
    printf(".\n");

    c = add_op(a, b);
    printf("The sum (first + second) equals: ");
    printf_value(c);
    printf(".\n");

    if (if_bigger(a, b)) {
        c = subtr_op(a, b);
        printf("The subtract (first - second) equals: ");
    } else {
        c = subtr_op(b, a);
        printf("The subtract (second - first) equals: ");
    }
    printf_value(c);
    printf(".\n");

    c = mult_op(a, b);
    printf("The product (first * second) equals: ");
    printf_value(c);
    printf(".\n");

    printf("We can get uint1024_t from unsigned int: %d. Here it is: ", ui);
    printf_value(from_uint(ui));
    printf(".\n");
}
