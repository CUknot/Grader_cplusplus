#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    string input;
    map<string,int> m;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> input;
        m[input]++;
    }
    auto maxit = m.begin();
    for (auto it = m.begin(); it != m.end(); it++){
        if (it->second >= maxit->second){
            maxit = it;
        }
    }
    cout << maxit->first << " " << maxit->second;
    return 0;
}
