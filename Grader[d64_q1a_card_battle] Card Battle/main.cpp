#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,input,amount;
    map<int,int> myCard;
    set<int> smyCard;
    cin >> n >> m;
    int output = m + 1;
    for (int i = 0; i < n; i++){
        cin >> input;
        myCard[input]++;
        smyCard.insert(input);
    }
    for (int i = 0; i < m; i++){
        cin >> amount;
        for (int j = 0; j < amount; j++){
            cin >> input;
            if (output == m + 1){
                auto it = smyCard.lower_bound(input + 1);
                if (it != smyCard.end()){
                    if (--myCard[*it] == 0){
                    smyCard.erase(it);
                    }
                }
                else{
                    output = i + 1;
                }
            }
        }
    }
    cout << output << endl;
    return 0;
}
