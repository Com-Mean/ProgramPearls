/*************************************************************************
    > File Name: bitsort.c
    > Author: lpqiu
    > Mail: lpqiu_1018@126.com 
    > Created Time: 2014年09月03日 星期三 04时22分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define BITPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
int a[1 + N/BITPERWORD];

void set(int i)
{
    a[i>>SHIFT] |= (1<<(i & MASK));
}

void clear(int i)
{
    a[i>>SHIFT] &= ~(1<<(i & MASK));
}

int test(int i)
{
    return a[i>>SHIFT] & (1<<(i & MASK));
}

int get_rand_nums(int n)
{
    int index = 0;
    int rand_v = 0;

    for(; index < N; index++)
        clear(index);

    index = 0;
    while(index < n)
    {
        rand_v = random(N);
        if(!test(rand_v))
        {
            printf("%d\n", rand_v);
            set(rand_v);
            index++;
        }
    }

    for(index = 0; index < N; index++)
    {
        clear(index);
    }

    return 0;
}

int main(void)
{
    int index;
    for(index = 0; index < N; index++)
    {
        clear(index);
    }

    while(EOF != scanf("%d", &index))
    {
        set(index);
    }

    for(index = 0; index < N; index++)
    {
        if(test(index))
            printf("%d\n", index);
    }

    return 0;
}
