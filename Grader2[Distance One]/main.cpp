#include <iostream>
#include <vector>

using namespace std;

vector<int> memo;
const int MOD = 100000007;

int DP(int n, int k) {
    if (n < 0) return 0; // No valid bit strings for negative lengths
    else if (n < k) return memo[n] = n + 1; // Base case
    else if (memo[n] != -1) return memo[n];
    else {
        memo[n] = (DP(n - 1, k) + DP(n - k, k))%MOD;
        return memo[n];
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    memo.resize(n + 1, -1); // Initialize memoization table

    cout << DP(n, k);
    return 0;
}
