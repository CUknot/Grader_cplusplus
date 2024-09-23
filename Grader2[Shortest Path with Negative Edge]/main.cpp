#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

typedef pair<int,int> pii;

int n;

vector<int> Bellman_Ford(int u, vector<vector<pii>> &G){
    vector<int> v(n, INT_MAX);
    v[u] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n; j++){
            for(auto x: G[j])
                v[j] = min(v[j], (v[x.first] == INT_MAX) ? INT_MAX:(v[x.first] + x.second));
        }
    }

    //check for negative cycles
     for(int j = 0; j < n; j++){
        for(auto x: G[j]){
            if(v[x.first] != INT_MAX && v[j] > v[x.first] + x.second)
                return {-1}; // Negative cycle detected
        }
     }
    return v;
}

int main()
{
    int ne,u;
    cin >> n >> ne >> u;
    vector<vector<pii>> G(n);
    for(int i = 0; i < ne; i++){
        int x,y,w;
        cin >> x >> y >> w;
        G[y].push_back({x,w});
    }
    for(auto x : Bellman_Ford(u,G)) cout << x << " ";
    return 0;
}
