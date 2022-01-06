#include <iostream>

using namespace std;

#define SIZE_MAX 2002

int main()
{
    bool* num = new bool[SIZE_MAX];

    for (int i = 0; i < SIZE_MAX; i++)
    {
        num[i] = false;
    }
    
    int length;
    cin >> length;

    int temp;

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &temp);
        num[temp + 1000] = true;
    }

    for (int i = 0; i <= SIZE_MAX; i++)
    {
        if (num[i] == true)
        {
            printf("%d ", i - 1000);
        }
    }
    delete[] num;

    return 0;
}
