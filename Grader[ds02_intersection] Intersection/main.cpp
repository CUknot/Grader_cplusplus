#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n, m, input;
    vector<int> v1, v2;
    cin >> n >> m;
    for(int i = 0; i < n; i++ ){
        cin >> input;
        v1.push_back(input);
    }
    for(int i = 0; i < m; i++ ){
        cin >> input;
        v2.push_back(input);
    }

    if (v1.size() > v2.size()){
        v1.swap(v2);
    }
    set<int> s2(v2.begin(),v2.end()), output;

    for (auto x: v1) {
        if(s2.find(x) != s2.end()){
            output.insert(x);
        }
    }

    for (auto x:output) {
        cout << x << " ";
    }
    return 0;
}
