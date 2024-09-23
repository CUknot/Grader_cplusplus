#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, int depth, vector<vector<int>>& ADJ_L, vector<bool>& visited) {
    int total = 0;
    queue<pair<int, int>> q; // Queue to store node and its depth

    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int current_depth = q.front().second;
        q.pop();

        if (current_depth <= depth) {
            total++; // Increment total if within depth limit

            // Explore neighbors
            for (auto neighbor : ADJ_L[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, current_depth + 1});
                }
            }
        }
    }

    return total;
}

int main() {
    int n, e, k;
    cin >> n >> e >> k;
    vector<vector<int>> ADJ_L(n);
    vector<bool> visited(n, false);
    vector<bool> ans(n, false);

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        ADJ_L[x].push_back(y);
        ADJ_L[y].push_back(x);
    }

    int max = -2e9;
    for (int i = 0; i < n; i++) {
        visited.assign(n, false);
        int temp = bfs(i, k, ADJ_L, visited);
        if (temp > max)
            max = temp;
    }
    cout << max << endl;
    return 0;
}

