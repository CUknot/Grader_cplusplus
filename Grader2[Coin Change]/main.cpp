#include <iostream>

using namespace std;

int* s;
int* memo;
int nset;

int DP(int n){
    if(memo[n] != -2) return memo[n];
    int minSplit = 2e9;
    for(int i = 0; i < nset; i++){
        if(n - s[i] >= 0) {
            int temp = DP(n - s[i]);
            if(temp + 1 < minSplit) minSplit = temp + 1;
        }
    }
    if(minSplit == 2e9) memo[n] = -1;
    else memo[n] = minSplit;
    return memo[n];
}

int main()
{
    int n;
    cin >> nset >> n;
    int temp1[nset];
    s = temp1;
    for(int i = 0; i < nset; i++) cin >> s[i];

    int temp2[n+1];
    memo = temp2;
    memo[0] = 0;
    for(int i = 1; i <= n; i++) memo[i] = -2;

    cout << DP(n) << "\n";
    //for(int i = 0; i <= n; i++) cout << memo[i];
    return 0;
}
