#include <iostream>
#include <vector>

using namespace std;

void perm(vector<int> &v, int idx, const int &n, int k){
    if(idx < n){
        v[idx] = 0;
        perm(v,idx + 1,n,k);
        if(k != 0){
            v[idx] = 1;
            perm(v,idx + 1,n,k - 1);
        }
    }
    else if(k == 0){
        for(auto x: v) cout << x;
        cout << "\n";
    }
}

int main()
{
    int n, k;
    cin >> k >> n;
    vector<int> v(n);
    perm(v,0,n,k);
    return 0;
}
