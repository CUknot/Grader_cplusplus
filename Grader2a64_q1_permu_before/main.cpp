#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> con;

bool enable(const vector<bool> &used){
    for(auto p: con){
        if(used[p.second] && !used[p.first]) return false;
    }
    return true;
}

void perm(int n,vector<int> &sol,int len,vector<bool> &used) {
    if (len < n) {
        for (int i = 0;i < n; i++) {
            if (used[i] == false) {
                used[i] = true;
                if(enable(used)) {
                    sol[len] = i;
                    perm(n,sol,len+1,used);
                }
                used[i] = false;
            }
        }
    }
    else {
        for (auto &x : sol) cout << x << " ";
        cout << endl;
    }
}
int main()
{
    int n,m,p1,p2;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
            cin >> p1 >> p2;
            con.push_back(make_pair(p1,p2));
    }
    vector<bool> used(n,false);
    vector<int> sol(n);
    perm(n,sol,0,used);
}
