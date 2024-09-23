#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void check(vector<int> &v, int input, int k);

int main()
{
    int n,m,k,input;
    vector<int> v;
    cin >> n >> m >> k;
    while (n--){
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(),v.end());
    while (m--){
        cin >> input;
        check(v, input, k);
    }
    return 0;
}

void check(vector<int> &v, int input, int k){
    auto it1 = lower_bound(v.begin(),v.end(),input - k);
    auto it2 = upper_bound(v.begin(),v.end(),input + k);
    printf("%d ", it2 - it1);
}


