/*************************************************************************
    > File Name: bitsort_1Mmem.c
    > Author: lpqiu
    > Mail: lpqiu_1018@126.com 
    > Created Time: 2014年09月03日 星期三 18时31分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITPERWORD 32       // sizeof(int) * BITEPERBYTE 
#define MAX_MEM_BIT 7340032 // 1024*1024*7 - 1
#define SHIFT 5             // 2**5 =32, used to calc the int value that the bit stay in
#define MASK 0x1F           // <=31的数, 一个int值能表示32bit，若每个bit代表一个数字，则能表示0~31之间的数
#define N 10000000

int a[1 + MAX_MEM_BIT/BITPERWORD];

void set(int i)
{
    a[i>>SHIFT]  |= (1<<(i & MASK));  // 或运算将指定的位置1,1左移到相应的位
}

void clear(int i)
{
    a[i>>SHIFT] &= ~(1<<(i & MASK));  // 与运算将相应的位置0
}

int test(int i)
{
    return a[i>>SHIFT] & (1<<(i & MASK)); // 相应位是否为1
}

int main(void)
{
    int index = 0, input = 0;
    int n = MAX_MEM_BIT - 1;
    memset(a, 0, 1 + MAX_MEM_BIT/BITPERWORD);
    while(EOF != scanf("%d", &input))
    {
        if(input > n)
            printf("%d ", input); // fprintf to a file, then exe this prog next time to get the result
        else
            set(input);
    }
    printf("\n");

    for(index = 0; index <= n; index++)
    {
        if(test(index))
        {
            printf("%d ", index); // fprintf to a result file
        }
    }
    printf("\n");
    return 0;
}

int exe_two_times_then_combine_the_result()
{
    /* first  time: ./a.out < input.txt  */
    /* second time: ./a.out < remain.txt  */
}
