#include <iostream>

using namespace std;

const int MOD = 1000003;
int nset;
int* s;
int* memo;

int DP(int n){
    if(memo[n] != -1) return memo[n];
    int total = 0;
    for(int i = 0; i < nset; i++){
        if(n - s[i] >= 0)total = (total + DP(n-s[i]))%MOD;
    }
    memo[n] = total;
    return memo[n];
}


int main()
{
    int n;
    cin >> n >> nset;
    int arr[nset];
    s = arr;
    int arr1[n+1];
    memo = arr1;
    memo[0] = 1;
    for(int i = 1; i <= n; i++) memo[i] = -1;
    for(int i = 0; i < nset; i++) cin >> s[i];

    cout << DP(n) << endl;
    return 0;
}
