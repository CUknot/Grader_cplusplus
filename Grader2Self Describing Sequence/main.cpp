#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;

void gen(int n){
    while(v.empty() || v.back().first < n){
        int ps = v.back().second + 1;
        int pf = lower_bound(v.begin(), v.end(), make_pair(ps,0))->second + v.back().first;
        v.push_back(make_pair(pf,ps));
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    v.push_back(make_pair(1,1));
    v.push_back(make_pair(3,2));
    int n;
    cin >> n;
    while(n--){
        int input;
        cin >> input;
        if(v.empty() || v.back().first < input){
            gen(input);
        }
        cout << lower_bound(v.begin(), v.end(), make_pair(input,0))->second << "\n";
    }
    /*gen(10);
    for(auto x: v){
        cout << "first: " << x.first << " ";
        cout << "second: " << x.second << "\n";
    }*/
    return 0;
}
