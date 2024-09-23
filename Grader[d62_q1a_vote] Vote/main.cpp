#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int K,N;
    string name;
    map<string,int> m;
    vector<pair<int,string>> v;
    cin >> K >> N;
    while(K--){
        cin >> name;
        m[name]++;
    }
    for(auto x: m){
        pair<int,string> p(x.second,x.first);
        v.push_back(p);
    }
    sort(v.rbegin(), v.rend()); // Sort in descending order

    if (N <= v.size()) {
        int nth_frequency = v[N - 1].first;

        for (int i = N - 1; i >= 0; i--) {
            if (v[i].first == nth_frequency) {
                cout << v[i].first << endl;
                break;
            }
        }
    }
    else {
        cout << v[v.size() - 1].first << endl;
    }
    return 0;
}
