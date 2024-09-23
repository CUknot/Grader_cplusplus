#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M, A;
    cin >> N >> M >> A;

    int itemQuantities[N];
    for (int i = 0; i < N; i++) {
        cin >> itemQuantities[i];
    }

    map<int, int> userBids[N]; //[item][user][value]

    for (int i = 0; i < A; i++) {
        char action;
        cin >> action;

        if (action == 'B') {
            int U, I, V;
            cin >> U >> I >> V;
            userBids[I - 1][U] = V;
        } else if (action == 'W') {
            int U, I;
            cin >> U >> I;
            userBids[I - 1].erase(U);
        }
    }

    // Determine the winners for each item type
    vector<vector<int>> winners(M);

    for (int item = 0; item < N; item++) {
        auto userBid = userBids[item];//map(user: prize)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> winofitem;// prize, user
        //find who is winner of this item
        for (auto pair: userBid) {
            winofitem.push(make_pair(pair.second,pair.first));
            if (winofitem.size() > itemQuantities[item]){
                winofitem.pop();
            }
        }
        //add that winner this item
        while (!winofitem.empty()){
            winners[winofitem.top().second - 1].push_back(item + 1);
            //cout << winofitem.top().second << " ";
            winofitem.pop();
        }
    }

    // Output the results
    for (auto x: winners){
        if (x.empty()){
            cout << "NONE";
        }
        else{
            for (auto y: x){
                cout << y << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
