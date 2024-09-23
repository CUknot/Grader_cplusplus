#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

const int MOD = 16777216;

// Heuristic function: estimates the number of steps needed to reach 0
int h(int x) {
    if (x == 0) return 0;

    // Count the number of trailing zeros in x
    int count = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        count++;
    }
    return count;
}

struct Node {
    int x;
    int steps;
    bool operator<(const Node& other) const {
        // Compare nodes based on steps + heuristic value
        return steps > other.steps;
        return steps + h(x) > other.steps + h(other.x);
    }
};

int main() {
    int x;
    cin >> x;

    // Edge case: if x is already 0
    if (x == 0) {
        cout << "0" << endl;
        return 0;
    }

    // Initialize priority queue and visited set
    priority_queue<Node> pq;
    unordered_set<int> visited;

    // Start Best-First Search
    pq.push({x, 0});
    while (!pq.empty()) {
        int curr_x = pq.top().x;
        int steps = pq.top().steps;
        pq.pop();
        //printf("curr_x: %d steps: %d \n", curr_x, steps);
        // Check if current x is 0
        if (curr_x == 0) {
            cout << steps << endl;
            return 0;
        }

        // Perform operation 1: (x + 1) % MOD
        int next_x = (curr_x + 1) % MOD;
        if (visited.find(next_x) == visited.end()) {
            visited.insert(next_x);
            pq.push({next_x, steps + 1});
        }

        // Perform operation 2: (x * 2) % MOD
        next_x = (curr_x * 2) % MOD;
        if (visited.find(next_x) == visited.end()) {
            visited.insert(next_x);
            pq.push({next_x, steps + 1});
        }
    }

    return 0;
}
