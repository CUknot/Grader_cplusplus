#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ans;
vector<vector<int>> split;

void calAns(int i, int j, vector<int> &arr) {
    int x = i + j + 1;
    int y = j;
    pair<int, int> minPair = {INT_MAX, -1}; // {minimum cost, index of split point}

    for (auto a = 1; a <= i + 1; a++) {
        int cost = ans[y][x - a] + ans[x - a + 1][x] + arr[y] * arr[x - a + 1] * arr[x + 1];
        if (cost < minPair.first) {
            minPair = {cost, x - a}; // Update minimum cost and split point index
        }
    }

    ans[y][x] = minPair.first;
    split[y][x] = minPair.second;
}

void printOptimalParentheses(int i, int j, bool outermost = true) {
    if (i == j) {
        cout << "M" << i;
    } else {
        if (!outermost) cout << "(";
        printOptimalParentheses(i, split[i][j], false);
        printOptimalParentheses(split[i][j] + 1, j, false);
        if (!outermost) cout << ")";
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 0; i <= n; i++) cin >> arr[i];

    ans.resize(n, vector<int>(n, 0));
    split.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (i + j + 1 < n) {
            calAns(i, j, arr);
            j++;
        }
    }

    cout << "Minimum number of scalar multiplications: " << ans[0][n - 1] << endl;
    cout << "Optimal parenthesis placement: ";
    printOptimalParentheses(0, n - 1);
    cout << endl;

    return 0;
}
