/*************************************************************************
    > File Name: qsort_file.c
    > Author: lpqiu
    > Mail: lpqiu_1018@126.com 
    > Created Time: 2014年09月03日 星期三 00时11分51秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int dataset[10000000] = {0}; // dataset maybe too large
    int index = 0, n = 10000000;

    while(index < n)
    {
        if(EOF == scanf("%d", &dataset[index++]))
                break;
    }

    //while(EOF != scanf("%d", &dataset[index++]));
    for(index = 0; index < n; index++)
        printf("%d ", dataset[index]);

    return 0;
}

