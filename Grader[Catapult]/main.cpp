#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Perform DFS to fill the stack with vertices in post-order
void dfs1(int v, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& finished) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u, adj, visited, finished);
        }
    }
    finished.push(v); // Push vertex after all its children are visited
}

// Perform DFS to find SCCs
void dfs2(int v, const vector<vector<int>>& radj, vector<bool>& visited, vector<int>& scc) {
    visited[v] = true;
    scc.push_back(v);
    for (int u : radj[v]) {
        if (!visited[u]) {
            dfs2(u, radj, visited, scc);
        }
    }
}

int main() {
    int N;
    cin >> N; // Number of houses

    // Initialize adjacency lists for original and reversed graphs
    vector<vector<int>> adj(N), radj(N);

    // Read the catapult setup for each house
    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M; // Number of catapults in this house
        adj[i].reserve(M);
        radj[i].reserve(M);
        for (int j = 0; j < M; ++j) {
            int target;
            cin >> target; // House numbers that the catapult can send a gift to
            adj[i].push_back(target);
            radj[target].push_back(i); // Reverse the edges for the reversed graph
        }
    }

    // First pass of Kosaraju's algorithm to fill the stack with vertices in post-order
    stack<int> finished;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs1(i, adj, visited, finished);
        }
    }

    // Second pass of Kosaraju's algorithm to find SCCs
    visited.assign(N, false);
    vector<vector<int>> SCCs;
    while (!finished.empty()) {
        int v = finished.top();
        finished.pop();
        if (!visited[v]) {
            vector<int> scc;
            dfs2(v, radj, visited, scc);
            SCCs.push_back(scc);
        }
    }

    // Output the size of the SCCs found
    sort(SCCs.begin(), SCCs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
    });
    for (const auto& scc : SCCs) {
        cout << scc.size() << " ";
    }

    return 0;
}
