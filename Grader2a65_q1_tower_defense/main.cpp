#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    vector<pair<int,int>> ph(m);
    vector<int> t(k);

    for(int i = 0; i < m;++i) cin >> ph[i].first;
    for(int i = 0; i < m;++i) cin >> ph[i].second;
    for(int i = 0; i < k;++i) cin >> t[i];

    sort(ph.begin(),ph.end());
    sort(t.begin(),t.end());

    auto itph = ph.begin();
    for(auto it = t.begin(); it != t.end(); ++it){
        while(*it > itph->first + w) itph++;
        if(*it - w <= itph->first && *it + w >= itph->first) {
                itph->second--;
                if(itph->second == 0) itph++;
                if(itph == ph.end()) break;
        }
    }

    int sum = 0;
    for(auto p:ph){
        sum += p.second;
    }
    cout << sum;

    return 0;
}
