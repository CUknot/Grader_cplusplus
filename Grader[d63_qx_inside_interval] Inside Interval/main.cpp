#include <iostream>
#include <map>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    map<int,int> map1;
    int n,m,input1,input2,check;
    cin >> n >> m;
    while(n--){
        cin >> input1 >> input2;
        map1[input1] = input2;
    }
    while(m--){
        cin >> check;
        auto it = map1.upper_bound(check);
        it--;
        if (it-> first <= check & it->second >= check){
           cout << "1 ";
        }
        else{
           cout << "0 ";
        }
    }
    return 0;
}
