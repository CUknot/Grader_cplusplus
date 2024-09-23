#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    string name;
    map<string,int> m;
    cin >> n;
    while(n--){
        cin >> name;
        m[name]++;
    }
    for(auto x:m){
        if (x.second > 1){
            cout << x.first << " " << x.second << endl;
        }
    }
    return 0;
}
