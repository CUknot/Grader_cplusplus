#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> input;
int memo[200005][55][2];

int TD(int n, int m, int k, bool isDown) {
    if (k == 0) return 0;
    else if (n < m) {
        return *max_element(input[isDown].begin(), input[isDown].begin() + n);
    }
    else if (memo[n][k][isDown] != -1) {
        return memo[n][k][isDown]; // Return memoized result if available
    }
    else {
        vector<int> findMax;
        if (n - 1 >= 0) findMax.push_back(TD(n - 1, m, k, isDown)); //ไม่เอาตัวท้าย
        if (n - m - 1 >= 0) findMax.push_back(TD(n - m - 1, m, k - 1, !isDown) + input[isDown][n]); //เอาตัวท้าย
        if (!findMax.empty()) memo[n][k][isDown] = *max_element(findMax.begin(), findMax.end());
        else memo[n][k][isDown] = 0;
        return memo[n][k][isDown];
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    input.resize(2, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> input[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> input[1][i];
    }

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        memo[i][0][0] = memo[i][0][1] = 0;
    }

    // Bottom-up DP
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            for (int isDown = 0; isDown <= 1; isDown++) {
                int& current = memo[i][j][isDown];
                current = max(current, memo[i - 1][j][isDown]); // Moving horizontally
                if (i >= m) {
                    int withoutLast = memo[i - 1][j][isDown]; // Not taking the last billboard
                    int withLast = memo[i - m][j - 1][!isDown] + input[isDown][i - 1]; // Taking the last billboard
                    current = max(current, withLast);
                }
            }
        }
    }

    cout << max(memo[n][k][0], memo[n][k][1]) << endl;
    return 0;
}
