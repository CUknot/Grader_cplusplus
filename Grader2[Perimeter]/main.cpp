#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dfs(int n, int k, vector<vector<int>> &G, vector<bool> &visited){
    queue<int> q1,q2;
    q1.push(n);
    visited[n] = true;
    while(k != 0){
        while(!q1.empty()){
            int temp = q1.front();
            q1.pop();
            //if(!visited[temp]){
                for(auto a: G[temp]){
                    if(!visited[a])
                        q2.push(a);
                        visited[a] = true;
                }
           // }
        }
        q1 = q2;
        k--;
        q2 = queue<int>();
    }
    return q1.size();
}

int main()
{
    int n,e,k;
    cin >> n >> e >> k;
    vector<vector<int>> G(n+1);
    vector<bool> visited(n+1,false);
    for(int i = 0; i < e; i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cout << dfs(0,k,G,visited);
    return 0;
}
