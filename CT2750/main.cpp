//
//  main.cpp
//  CT2750
//
//  Created by 함범진 on 2022/01/04.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int length;
    cin>>length;
    
    vector<int> num(length);
    
    int temp;
    
    for(int i =0; i<length; i++)
    {
        cin>>temp;
        num.at(i) = temp;
    }
    
    sort(num.begin(), num.end());
    
    for(int i=0;i<length;i++)
        cout << num.at(i) << endl;
    
    return 0;
}
