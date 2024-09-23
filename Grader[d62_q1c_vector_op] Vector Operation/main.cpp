#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n,input;
    string order;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> order;
        if (order == "pb"){
            cin >> input;
            v.push_back(input);
        }
        else if(order == "sa"){
            sort(v.begin(), v.end());
        }
        else if(order == "sd"){
            sort(v.begin(), v.end(), greater<int>());
        }
        else if(order == "r"){
            reverse(v.begin(),v.end());
        }
        else if(order == "d"){
            cin >> input;
            v.erase(v.begin() + input);
        }
    }
    for (auto x: v){
        cout << x << " ";
    }
    return 0;
}
