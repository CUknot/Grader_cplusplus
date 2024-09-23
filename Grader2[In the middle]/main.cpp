#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int n, vector<vector<int>> &G, vector<bool> &visited, vector<int> &dist){
    queue<pair<int,int>> q;
    q.push({n,0});
    while(!q.empty()){
        pair<int,int> temp = q.front();
        dist[temp.first] = temp.second;
        q.pop();
        if(!visited[temp.first]){
            visited[temp.first] = true;
            for(auto x: G[temp.first]){
                if(!visited[x]) q.push({x,temp.second+1});
            }
        }
    }
}

int main()
{
    int n,x1,x2,x3;
    cin >> n >> x1 >> x2 >> x3;
    vector<vector<int>> G(n+1);
    for(int i = 1; i <= n; i++){
        int amount;
        cin >> amount;
        G[i].resize(amount);
        for(int j = 0; j < amount; j++) cin >> G[i][j];
    }
    vector<bool> visited1(n+1,false);
    vector<bool> visited2(n+1,false);
    vector<bool> visited3(n+1,false);
    vector<int> dist1(n+1,2e9);
    vector<int> dist2(n+1,2e9);
    vector<int> dist3(n+1,2e9);
    bfs(x1,G,visited1,dist1);
    bfs(x2,G,visited2,dist2);
    bfs(x3,G,visited3,dist3);
    /*for(auto a : G){
        for(auto b: a) cout << b << " ";
        cout << "\n";
    }
    printf("1: ");
    for(int i = 1; i < n + 1; i++) cout << dist1[i] << " ";
    cout << "\n";
    printf("2: ");
    for(int i = 1; i < n + 1; i++) cout << dist2[i] << " ";
    cout << "\n";
    printf("3: ");
    for(int i = 1; i < n + 1; i++) cout << dist3[i] << " ";
    cout << "\n";*/
    int m = 2e9;
    for(int i = 1; i <= n; i++) m = min(m,max({dist1[i],dist2[i],dist3[i]}));
    cout << m;
    return 0;
}
