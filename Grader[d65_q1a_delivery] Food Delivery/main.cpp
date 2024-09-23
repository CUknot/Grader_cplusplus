#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,m,k,input,shopnumber,prize;
    queue<int> q[2];
    vector<int> prizegoal;
    vector<int> v = {0};

    cin >> n >> m;

    while(m--){
        cin >> k;
        prizegoal.push_back(k);
    }

    while(n--){
        cin >> input;
        if (input == 1){
            cin >> shopnumber;
            cin >> prize;
            (q[shopnumber - 1]).push(prize);
        }
        else if(input == 2){
            int i = 0;
            if((q[0]).empty()){
                i = 1;
            }
            else if (!(q[1]).empty() && (q[0]).front() > (q[1]).front()){
                i = 1;
            }
            v.push_back((q[i]).front() + v.back());
            (q[i]).pop();
        }
    }

    for(auto x : prizegoal){
        size_t index = lower_bound(v.begin(),v.end(),x) - v.begin();
        if (index == v.size()){
            cout << "-1 ";
        }
        else{
            cout << index << " ";
        }
    }

    return 0;
}
