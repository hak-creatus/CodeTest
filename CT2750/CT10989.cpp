//
//  CT10989.cpp
//  CT2750
//
//  Created by 함범진 on 2022/01/05.
//

#include <iostream>

using namespace std;

int main()
{
    int* num = new int[10001];

    for (int i = 0; i <= 10000; i++)
    {
        num[i] = 0;
    }
    
    int length;
    cin >> length;

    int temp;

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &temp);
        num[temp]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < num[i]; j++)
        {
            printf("%d\n",i);
        }
    }
    delete num;

    return 0;
}
