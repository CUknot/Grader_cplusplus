#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll A,B;

ll numAvenger(int begin, int n, const vector<int> &v){
    return lower_bound(v.begin(),v.end(),begin + n) - lower_bound(v.begin(),v.end(),begin);
}

ll rec(int begin, int n, const vector<int> &v){
    if(n == 0) return 0;
    ll na = numAvenger(begin, n, v);
    if(na == 0) return A;
    if(n > 1){
        return min(na * B * n, rec(begin, n/2, v) + rec(begin + n/2, n/2, v));
    }
    else if(n == 1) {
        return B * na;
    }
    return 0; // Added to suppress warning
}

int main()
{
    int p,k;
    cin >> p >> k >> A >> B;
    vector<int> v(k);
    ll temp = 1;
    for(int i = 0; i < p; i++) temp *= 2;
    for(int i = 0; i < k; i++) cin >> v[i];
    sort(v.begin(),v.end());
    cout << rec(1,temp,v);
    return 0;
}
