/*************************************************************************
    > File Name: qsort_file.cpp
    > Author: lpqiu
    > Mail: lpqiu_1018@126.com 
    > Created Time: 2014年09月03日 星期三 01时39分04秒
 ************************************************************************/

#include<iostream>
#include <set>
#include <iterator>
using namespace std;

int main(void)
{
    set<int> dataSet;
    int i;
    set<int>::iterator iter;

    while(cin >> i)
        dataSet.insert(i);

    for(iter = dataSet.begin(); iter != dataSet.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
