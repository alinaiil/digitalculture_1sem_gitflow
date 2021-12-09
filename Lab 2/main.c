#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int base = 1000000000;

typedef struct {
    int value[35];
} uint1024_t;

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
