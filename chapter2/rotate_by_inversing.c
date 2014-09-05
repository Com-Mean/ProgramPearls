/*************************************************************************
    > File Name: rotate_by_inversing.c
    > Author: lpqiu
    > Mail: lpqiu_1018@126.com 
    > Created Time: 2014年09月05日 星期五 22时57分52秒
 ************************************************************************/

#include <stdio.h>

#define FAILURE 1
#define SUCCESS 0

int inverseVector(int * const start, int * const end)
{
    if(NULL == start || NULL == end || start >= end)
    {
        return FAILURE;
    }

    int swap = 0;
    int *start_ptr = start;
    int *end_ptr = end;

    while(start_ptr < end_ptr)
    {
        swap = *start_ptr;
        *start_ptr = *end_ptr;
        *end_ptr = swap;
        start_ptr++;
        end_ptr--;
    }
    return SUCCESS;
}

int rotateLeft(int *dataSet, int set_len, int shift_num)
{
    if(NULL == dataSet || 0 == set_len * shift_num)
    {
        return FAILURE;
    }

    shift_num = shift_num/set_len;
    inverseVector(&dataSet[0], &dataSet[shift_num - 1]);
    inverseVector(&dataSet[shift_num], dataSet[set_len - 1]);
    inverseVector(&dataSet[0], &dataSet[set_len - 1]);
    return SECCESS
}

int rotateRight(int *dataSet, int set_len, int shift_num)
{
    if(NULL == dataSet || 0 == set_len * shift_num)
    {
        return FAILURE;
    }

    shift_num = shift_num/set_len;
    inverseVector(&dataSet[set_len - shift_num], dataSet[set_len - 1]);
    inverseVector(&dataSet[0], &dataSet[set_len - shift_num]);
    inverseVector(&dataSet[0], &dataSet[set_len - 1]);
    return SECCESS

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
