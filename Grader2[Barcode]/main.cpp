#include <iostream>

using namespace std;

int m;
int memo[31][31];

int DP(int n, int k){
    if(memo[n][k] != -1) return memo[n][k];
    if(k == 0) {
        memo[n][k] = n <= m;
        return memo[n][k];
    }
    int total = 0;
    for(int i = 1; i <= m; i++) if(n-i > 0) total += DP(n - i,k - 1);
    memo[n][k] = total;
    //printf("%d %d %d \n",n,k,total);
    return memo[n][k];
}

int main()
{
    int n,k;
    cin >> n >> m >> k;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            memo[i][j] = -1;
        }
    }

    cout << DP(n,k) << endl;
    return 0;
}
