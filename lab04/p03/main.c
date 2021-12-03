#include <stdio.h>

#define N 5
#define M 3

void printArray(int *beg, int *end)
{
    // for(int i = 0; i < n; ++i)
    // {
    //     printf("%d", p[i]);
    // }

    // int *end = p + n;
    // for(; p != end; ++p)
    // {
    //     printf("%d", *p);
    // }

    while (beg != end)
    {
        printf("%d", *beg++);
    }
    printf("\n");
}

int main(void)
{
    int a[N];
    int b[M];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", a + i);
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d", b + i);
    }

    printArray(a, a + N);
    printArray(b, b + M);
}