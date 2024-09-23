#include <iostream>
#include <vector>

using namespace std;

int k;

bool con(const vector<int> &v){
    int count = 0;
    for(auto x: v){
        if (x == 1) count += 1;
        else count = 0;
        if (count == k) return true;
    }
    return false;
}

void perm(vector<int> &v, int idx, int n){
    if(idx < n) {
        v[idx] = 0;
        perm(v,idx + 1,n);
        v[idx] = 1;
        perm(v,idx + 1,n);
    }
    else if(con(v)){
        for(auto x: v) cout << x;
        cout << "\n";
    }
}
int main()
{
    int n;
    cin >> n >> k;
    vector<int> v(n);

    perm(v,0,n);
    return 0;
}
