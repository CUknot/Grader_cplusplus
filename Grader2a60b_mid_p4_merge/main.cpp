#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;

    vector<int> v;
    v.push_back(n);
    int count = 0;
    auto it = v.begin();
    while(v.size() + count < k){
        if (it == v.end()) {cout << -1; return 0;}
        int temp = *it;
        if(temp == 1){it++; continue;}
        it = v.erase(it);
        count += 1;
        it = v.insert(it,(temp + 1)/2);
        it = v.insert(it,temp/2);
    }

    for(auto x:v){
        for(int i = n - x; i < n; i++){
            cout << i + 1 << " ";
        }
        n -= x;
        //cout << x << " ";
    }
    return 0;
}
