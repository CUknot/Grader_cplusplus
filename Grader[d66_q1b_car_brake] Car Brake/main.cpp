#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;

    vector<pair<int,int>> v;
    while(n--){
        pair<int,int> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(),v.end());

    auto it = v.begin();
    set<pair<int,int>> vp;
    int d = 0;
    while(vp.empty()||vp.back().second != 0){
        vp.insert(make_pair(d,k));
        d = it->first;
        k -= it->second;
        if(k < 0) k = 0;
        it++;
    }

    /*for (auto x: vp){
        cout << x.first << " " << x.second << "\n";
    }*/

    while(m--){
        int a,q;
        cin >> a >> q;
        auto it = vp.begin();
        if(a == 1){
            while(it->first <= q)it++;
            it--;
            cout << it->second << "\n";
        }
        else if(a == 2){
            while(it->second >= q)it++;
            cout << it->first << "\n";
        }
    }
    return 0;
}
