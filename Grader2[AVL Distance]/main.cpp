#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edge;

int countChildrenAtHeight(int n, int k) {
    if(k > 0){
        int total = 0;
        for(auto child: edge[n]) total += countChildrenAtHeight(child,k-1);
        return total;
    }
    else return 1;
}

int main()
{
    int n,k,a,b;
    cin >> n >> k;
    edge.resize(n + 1);
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        edge[a].push_back(b);
        //edge[b].push_back(a);
    }
    int total = 0;
    for(int i = 1; i <= n; i++){
        int s = edge[i].size();
        if(s == 1) total += countChildrenAtHeight(edge[i][0], k - 1);
        else if(s == 2){
            total += countChildrenAtHeight(edge[i][0], k - 1);
            total += countChildrenAtHeight(edge[i][1], k - 1);
            for(int j = 0; j < k - 1; j++){
            total += countChildrenAtHeight(edge[i][0], j) * countChildrenAtHeight(edge[i][1], k - 2 - j);
            }
        }


    }
    cout << total << "\n";
    return 0;
}

