#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

void KahnTopoSort(vector<vector<int>> &G, vector<int> &inDeG){
    vector<int> ans;
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDeG[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);

        for(auto x: G[u]){
            if(--inDeG[x] == 0) q.push(x);
        }
    }
    for (int num : ans) {
        cout << num << " ";
    }
}

int main()
{
    cin >> n;
    vector<vector<int>> G(n);
    vector<int> inDeG(n,0);
    for(int i = 0; i < n; i++){
        int m,y;
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> y;
            G[y].push_back(i);
            inDeG[i]++;
        }
    }
    KahnTopoSort(G,inDeG);
    return 0;
}
