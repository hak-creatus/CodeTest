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

    while (length--) {
        scanf("%ld %ld", &x, &y);
        loc.push_back(make_pair(x, y));
    }

    sort(loc.begin(), loc.end());

    for (int i = 0; i < loc.size(); i++) {
        printf("%ld %ld\n", loc[i]);
    }

    return 0;
}
