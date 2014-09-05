/*************************************************************************
    > File Name: rotateLeft.c
    > Author: lpqiu
    > Mail: lpqiu_1018@126.com 
    > Created Time: 2014年09月05日 星期五 19时00分56秒
 ************************************************************************/

#include <stdio.h>

#define FAILURE  0
#define SUCCESS  1

// using the euclidean algorithm to calc gcd
int getGcd(int a, int b)
{
    if(0 == a || 0 == b)
    {
        return 0;
    }

    if(1 == a || 1 == b)
    {
        return 1;
    }

    // let a is the bigger one
    int swap = a;
    if(a < b)
    {
        a = b;
        b = swap;
    }

    while(0 != (swap = a%b))
    {
        if(b > swap)
        {
            a = b;
            b = swap;
        }
        else
        {
            a = swap;
        }
    }

    return b;
}

int rotateLeft(int *data_set, int set_len, int shift_num)
{
    int i = 0, j = 1, gcd = 0, start = 0;

    if(NULL == data_set || 0 == set_len)
    {
        return FAILURE;
    }

    shift_num %= set_len;
    gcd = getGcd(set_len, shift_num);

    for(; i < gcd; i++)
    {
        start = data_set[i];
        j = i;
        while(j % set_len != 0)
        {
            data_set[i % set_len] = data_set[(j + shift_num) % set_len];
            j += shift_num;
        }
        data_set[j % set_len] = start;
    }

    return SUCCESS;
}

int main()
{
    int a[] = {1, 2, 3, 4};
    printf("Original Vector:");
    for(int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    rotateLeft(a, sizeof(a)/sizeof(int), 2); 
    printf("rotated left(%d) Vector:", 2);
    for(int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
