#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    typedef pair<int,int> pii;
    //Bellman-Ford
    int n;
    cin >> n;
    vector<vector<pii>> G(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            if(temp != -1 && temp != 0) G[i].push_back({j,temp});
        }
    }
    vector<int> v(n,2e9);
    v[0] = 0;
    for(int i = 0; i < n-1; i++){
        for(int idx = 0; idx < n; idx++){
            for(auto u: G[idx]) v[u.first] = min(v[u.first], v[idx] + u.second);
        }
    }

    //for(auto x: v) cout << x << " ";
    int max_distance = *max_element(v.begin(),v.end());
    //cout << max_distance;
    cout << ((max_distance == 2e9) ? -1 : max_distance);
    return 0;
}
