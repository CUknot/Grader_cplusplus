#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,x,y;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v[i] = make_pair(x,y);
    }
    sort(v.begin(),v.end());
    int m = 0;
    int c = 0;
    for(auto it = v.rbegin(); it != v.rend(); it++){
        if(it->second > m){
            m = it->second;
            c++;
        }
    }
    cout << c << "\n";
    return 0;
}
