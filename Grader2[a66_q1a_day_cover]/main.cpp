#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

void dayCover(int x, vector<bool> v, bool* used, vector<int>* data, int length, int& min_length) {
    if (length >= min_length || length >= n) { // Stop recursion if length exceeds minimum or n
        return;
    }

    for (auto y : data[x]) v[y] = true;

    if (v == vector<bool>(n, true)) {
        if (length < min_length) {
            min_length = length;
        }
        return;
    }

    used[x] = true;
    for (int i = m - 1; i > x; i--) {
        if (!used[i]) {
            dayCover(i, v, used, data, length + 1, min_length);
        }
    }
    used[x] = false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    vector<bool> v(n, false);
    bool used[m] = { false };
    vector<int> data[m];
    for (int i = 0; i < m; i++) {
        int action;
        cin >> action;
        for (int j = 0; j < action; j++) {
            int temp;
            cin >> temp;
            data[i].push_back(temp - 1);
        }
    }

    int min_length = 2e9; // Initialize min_length with a large value
    for (int i = 0; i < m; i++) {
        dayCover(i, v, used, data, 1, min_length);
    }

    if (min_length == 2e9) {
        cout << "No solution found";
    } else {
        cout << min_length;
    }

    return 0;
}
