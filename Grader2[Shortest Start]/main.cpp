#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Bellman-Ford
    typedef pair<int,int> pii;
    int n,m,k,target;
    cin >> n >> m >> k >> target;
    vector<int> start(k);
    for(int i = 0; i < k; i++) cin >> start[i];

    vector<vector<pii>> G(n);
    for(int i = 0; i < m; i++){
        int x,y,w;
        cin >> x >> y >> w;
        G[y].push_back({x,w});
    }

    vector<int> v(n,2e9);
    v[target] = 0;
    for(int i = 0; i < n - 1; i++){
        for(int idx = 0; idx < n; idx++){
            for(auto u : G[idx]){
                v[u.first] = min(v[u.first], v[idx] + u.second);
            }
        }
    }

    //for(auto u : v) cout << u << " ";
    int minW = 2e9;
    for(auto u: start) minW = min(minW, v[u]);
    cout << minW;
    return 0;
}
