#include <iostream>
#include <vector>

using namespace std;

void dfs(int a, vector<vector<int>> &ADJ_L, vector<bool> &visited){
    visited[a] = true;
    for(auto b: ADJ_L[a]){
        if(!visited[b])
            dfs(b,ADJ_L,visited);
    }
}

int main()
{
    int n,e;
    cin >> n >> e;
    vector<vector<int>> ADJ_L(n+1);
    for(int i = 0; i < e; i++){
        int x,y;
        cin >> x >> y;
        ADJ_L[x].push_back(y);
        ADJ_L[y].push_back(x);
    }
    vector<bool> visited(n,false);

    int c = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]) {
            dfs(i,ADJ_L,visited);
            c++;
        }
    }
    cout << c;
    return 0;
}
