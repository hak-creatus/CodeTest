//
//  CT10816.cpp
//  CT2750
//
//  Created by 함범진 on 2022/01/12.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int length;
bool che[10];
int arr[10], A[10];
int maximum = 0;

void cal()
{
    int sum = 0;
    for (int i = 1; i < length; i++)
        sum += abs((int)(arr[i] - arr[i + 1]));
    
    if (maximum < sum)
        maximum = sum;
    
    return;
}
void dfs(int k)
{
    if (k > length)
    {
        cal();
        return;
    }
    for (int i = 1; i <= length; i++)
    {
        if (che[i] == false)
        {
            che[i] = true;
            arr[k] = A[i];
            dfs(k + 1);
            che[i] = false;
        }
    }
}
int main()
{
    scanf("%d", &length);
    
    for (int i = 1; i <= length; i++)
        scanf("%d", &A[i]) ;
    
    for (int i = 1; i <= length; i++)
    {
        che[i] = true;
        arr[1] = A[i];
        dfs(2); // 2번째 자리부터 함수 알맞은 값을 구하기 위해 연산을 시작함.
        che[i] = false;
    }
    
    printf("%d\n", maximum);
    
    return 0;
}
