#include <iostream>
#include <vector>

using namespace std;

bool dfs_cd(int a, vector<vector<int>>& AdjacencyList, vector<bool>& used, int parent){
    used[a] = true;
    for(auto b: AdjacencyList[a]){
        if (!used[b]){
            if (dfs_cd(b, AdjacencyList, used, a))
                return true;
        }
        else if (b != parent){
            return true;
        }
    }
    return false;
}

bool CheckCycle(vector<vector<int>>& AdjacencyList, int N){
    // using dfs
    vector<bool> used(N, false);
    for(int i = 0; i < N; i++){
        if(!used[i]){
            if(dfs_cd(i, AdjacencyList, used, -1)) return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int nGraph;
    cin >> nGraph;
    for(int i = 0; i < nGraph; i++){
        int N, E;
        cin >> N >> E;
        vector<vector<int>> AdjacencyList(N);
        for(int j = 0; j < E; j++){
            int x, y;
            cin >> x >> y;
            AdjacencyList[x].push_back(y);
            AdjacencyList[y].push_back(x);
        }
        if(CheckCycle(AdjacencyList, N)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
