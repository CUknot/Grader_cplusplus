#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> hole;

int bfs_min(int sx, int sy) {
    int minHole = 2e9;
    vector<vector<bool>> visited(1000, vector<bool>(1000, false));
    queue<pair<pair<int,int>, int>> q;
    q.push({{sx, sy},0});
    visited[sy][sx] = true;
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // If the current cell
            if (nx < 0 || ny < 0 || nx >= 1000 || ny >= 1000) {
                minHole = min(minHole,c);
            }

            // Check if the next cell is unvisited
            else if (!visited[ny][nx]) {
                q.push({{nx, ny},c + hole[ny][nx]});
                visited[ny][nx] = true;
            }
        }
    }

    return minHole;
}

int main() {
    int n, hx, hy;
    cin >> n >> hx >> hy;
    hole.resize(1000, vector<bool>(1000, false));

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        hole[y - 1][x - 1] = true;
    }

    cout << bfs_min(hx - 1, hy - 1) << endl;
    return 0;
}
