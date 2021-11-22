#include <stdio.h>

int main(void)
{
    int x;
    int y;
    int *p;

    x = 1;
    p = &x;

    printf("x = %d\n", x);
    printf("x = %d\n", *p);

    printf("Hello, world\n");
}