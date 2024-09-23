#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;

int getMinbfs(int startX, int startY, vector<vector<bool>>& arr, vector<vector<bool>>& visited) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{startX, startY}, 0});
    visited[startY][startX] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int current_length = q.front().second;
        q.pop();

        if (y == R && x == C)
            return current_length;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 1 && newX <= C && newY >= 1 && newY <= R && arr[newY][newX] && !visited[newY][newX]) {
                visited[newY][newX] = true;
                q.push({{newX, newY}, current_length + 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> R >> C;
    vector<vector<bool>> arr(R + 2, vector<bool>(C + 2, false));

    for (int i = 1; i <= R; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= C; j++) {
            if (row[j - 1] == '.') // Corrected indexing
                arr[i][j] = true;
            else
                arr[i][j] = false;
        }
    }

    vector<vector<bool>> visited(R + 2, vector<bool>(C + 2, false));
    for (int i = 0; i <= R + 1; i++) {
        visited[i][0] = true;
        visited[i][C + 1] = true;
    }
    for (int i = 0; i <= C + 1; i++) {
        visited[0][i] = true;
        visited[R + 1][i] = true;
    }

    cout << getMinbfs(1, 1, arr, visited);
    return 0;
}
