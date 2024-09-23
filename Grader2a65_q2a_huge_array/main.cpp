#include <iostream>
#include <map>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,x,y;
    map<int,int> map, rmap;
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        cin >> x >> y;
        map[x] += y;
    }
    int total = 0;
    for(auto x: map){
      rmap[total] = x.first;
      total += x.second;
    }
    /*for(auto x: rmap){
      cout << x.first << " " << x.second << "\n";
    }*/
    for(int i = 0; i < m ; i++){
        cin >> x;
        cout << (--rmap.upper_bound(x - 1))->second << "\n";
    }
    return 0;
}
