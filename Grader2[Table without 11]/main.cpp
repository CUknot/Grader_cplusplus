#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo(3);
const int MOD = 100000007;

long long DP(int n, int type){
    if(n <= 1) return 1LL;
    else if(memo[type][n] != -1) return memo[type][n];
    else{
        int ans;
        if(type == 0) ans = (DP(n-1,0) + DP(n-1,1) + DP(n-1,2))%MOD;
        else if(type == 1) ans = (DP(n-1,0) + DP(n-1,2))%MOD;
        else if(type == 2) ans = (DP(n-1,0) + DP(n-1,1))%MOD;
        else ans = -1;
        memo[type][n] = ans;
        return memo[type][n];
    }
    return -1;
}

int main()
{
    int n;
    long long ans = 0;
    cin >> n;
    for(int i = 0; i < 3; i++) memo[i].resize(n+1,-1);
    for(int i = 0; i < 3; i++) ans += DP(n,i);

    cout << ans % MOD;
    return 0;
}
