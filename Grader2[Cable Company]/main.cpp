#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> pii;  // Pair of (weight, vertex)

// Function to implement Prim's algorithm and return the total weight of the MST
int primMST(vector<vector<pii>>& graph, int start) {
    int V = graph.size();
    vector<bool> visited(V, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-Heap of pairs (weight, vertex)

    // Start with the given vertex
    pq.push({0, start});
    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        // If vertex u is already visited, continue
        if (visited[u]) continue;

        // Mark vertex u as visited
        visited[u] = true;

        // Add weight to total weight of MST
        totalWeight += w;

        // Explore adjacent vertices
        for (auto& edge : graph[u]) {
            int v = edge.second;
            int weight = edge.first;
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    return totalWeight;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pii>> G(n,vector<pii>(n));
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            //printf("(%d %d)", i,j);
            int temp;
            cin >> temp;
            G[i].push_back({temp,j});
            G[j].push_back({temp,i});
        }
    }
    cout << primMST(G,0);
    return 0;
}
