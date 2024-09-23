#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    typedef pair<int,int> pii;
    int N,M,Q;
    cin >> N >> M >> Q;
    vector<vector<pii>> G(N);
    for(int i = 0; i < M; i++){
        int x,y,w;
        cin >> x >> y >> w;
        G[x].push_back({y,w});
        G[y].push_back({x,w});
    }
    //using Prim's Algorithm
    vector<int> ans;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    vector<bool> visited(N);
    q.push({0,0});
    while(!q.empty()){
        int w = q.top().first;
        int u = q.top().second;
        q.pop();

        if(visited[u]) continue;
        visited[u] = true;
        ans.push_back(w);

        for(auto v: G[u]){
            if(!visited[v.first]) q.push({v.second,v.first});
        }
    }

    sort(ans.rbegin(),ans.rend());
    for(auto x: ans) cout << x << " ";
    for(int i = 0; i < Q; i++){
        int temp;
        cin >> temp;
        cout << ans[temp - 1] << "\n";
    }
    return 0;
}
