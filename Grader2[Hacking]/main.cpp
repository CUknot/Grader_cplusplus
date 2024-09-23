#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> input(k), time(n);
    vector<vector<int>> G(n);
    for(int i = 0; i < k; i++) cin >> input[i];
    for(int i = 0; i < n; i++) cin >> time[i];
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    typedef pair<int,int> pii;
    //using Prim's algorithm
    vector<bool> visited(n,false);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    int final_time = 0;
    for(auto x: input) q.push({time[x],x});
    while(!q.empty()){
        int t = q.top().first;
        int idx = q.top().second;
        q.pop();

        if(visited[idx]) continue;
        visited[idx] = true;
        final_time = t;

        for(auto u : G[idx]){
            if(!visited[u]) q.push({t + time[u], u});
        }
    }
    cout << final_time;
    return 0;
}
