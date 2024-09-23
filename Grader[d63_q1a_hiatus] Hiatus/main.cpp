#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,year,month;
    vector<pair<int,int>> v;
    cin >> n >> m;
    while(n--){
        cin >> year >> month;
        pair<int,int> p(year,month);
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    while(m--){
        cin >> year >> month;
        pair<int,int> p(year,month);
        auto it = upper_bound(v.begin(),v.end(),p);
        if (it == v.begin()){
            printf("-1 -1 ");
        }
        else if(*(--it) == p){
            printf("0 0 ");
        }
        else{
            printf("%d %d ",it->first,it->second);
        }
    }
    return 0;
}
