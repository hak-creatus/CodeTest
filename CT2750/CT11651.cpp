//
//  CT11651.cpp
//  CT2750
//
//  Created by 함범진 on 2022/01/10.
//

#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int length;
    int x, y;
    scanf("%d", &length);

    vector<pair<long, long>> loc;

    while (length--)
    {
        scanf("%ld %ld", &x, &y);
        loc.push_back(make_pair(y, x));
    }

    sort(loc.begin(), loc.end());

    for (int i = 0; i < loc.size(); i++)
    {
        printf("%ld %ld\n", loc[i].second, loc[i].first);
    }

    return 0;
}
