#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> AdjacencyList;

bool dfs_lg(int a, vector<bool> &used, int previous){
    bool result = true;
    used[a] = true;

    if(AdjacencyList[a].size() > 2) result = false;
    for(auto x: AdjacencyList[a]){
        if(!used[x]) {if(!dfs_lg(x, used, a)) result = false;}
        else if(x != previous && previous != -1) result = false;
    }
    /*printf("a: %d used: ", a);
    for(auto  x: used) cout << x << " ";
    printf("perv: %d result: %d \n", previous, result);*/
    return result;
}

int main()
{
    int n,e;
    cin >> n >> e;
    AdjacencyList.resize(n);
    for(int i = 0; i < e; i++){
        int x,y;
        cin >> x >> y;
        AdjacencyList[x].push_back(y);
        AdjacencyList[y].push_back(x);
    }

    vector<bool> used(n,false);
    int c = 0;
    for(int i = 0; i < n; i++){
        if(!used[i]) {
            if(dfs_lg(i,used,-1)) c++;
        }
    }
    cout << c << "\n";
    return 0;
}
