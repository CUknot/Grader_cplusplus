#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int nnode, ncondi;
    cin >> nnode >> ncondi;
    vector<vector<int>> G(nnode+1);

    for(int i = 0; i < ncondi; i++){
        int x, y;
        cin >> x >> y;
        G[y].push_back(x);
    }

    for(int i = 0; i < 5; i++){
        vector<bool> visited(nnode+1,false);
        bool b = false;
        for(int j = 0; j < nnode; j++){
            int temp;
            cin >> temp;
            if(b) continue;
            visited[temp] = true;
            for(auto u: G[temp]){
                if(!visited[u]){
                    b = true;
                    break;
                }
            }
        }
        if(b) cout << "FAIL\n";
        else  cout << "SUCCESS\n";
    }
    return 0;
}
