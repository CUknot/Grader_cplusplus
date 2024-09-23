#include <iostream>
#include <vector>

using namespace std;

int nday,nperson;
int ans = 2e9;
vector<vector<int>> d;

void perm(int len, int n, int c, vector<int> &sol){
    if(len < n){
        perm(len + 1, n ,c, sol);
        if(c < ans){
            for(auto x: d[len]) (sol[x])++;
            bool con = true;
            for(int i = 0; i < nday; i++) {
                if(sol[i] == 0) {con = false; break;}
            }
            if(con) {
                if(c + 1 < ans) ans = c + 1;
                for(auto x: d[len]) (sol[x])--;
                return;
            }
            perm(len + 1, n ,c + 1, sol);
            for(auto x: d[len]) (sol[x])--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> nday >> nperson;
    d.resize(nperson);
    for(int i = 0; i < nperson; i++){
        int action;
        cin >> action;
        d[i].resize(action);
        for(int j = 0; j < action; j++) {
            int temp;
            cin >> temp;
            d[i][j] = temp - 1;
        }
    }
    vector<int> sol(nday,0);
    perm(0, nperson, 0, sol);
    cout << ans;
}
