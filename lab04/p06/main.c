#include <stdio.h>
#include <stdlib.h>

#include "VecInt.c"

void printArray(int *beg, int *end)
{
    while (beg != end)
    {
        printf("%d ", *beg++);
    }
    printf("\n");
}

void reverse(int *beg, int *end)
{
    for (;;)
    {
        if (beg == end)
        {
            break;
        }
        --end;

        if (beg == end)
        {
            break;
        }

        int t = *beg;
        *beg = *end;
        *end = t;

        ++beg;
    }
}

void p02()
{
    struct VecInt v;
    VecInt_createEmpty(&v);

    int x;
    while (scanf("%d", &x) == 1)
    {
        VecInt_pushBack(&v, x);
    }

    printArray(v.data, v.data + v.sz);
    reverse(v.data, v.data + v.sz);
    printArray(v.data, v.data + v.sz);
}

int main(void)
{
    p02();
}