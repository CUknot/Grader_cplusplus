#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void createMoreTotal(vector<int> &total, priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> &q, int &s, int &p){
    if (total.empty()) total.push_back(s);
    while(p > total.back()){
        if (!q.empty() && total.size() == q.top().first) {
                s = q.top().second;
                q.pop();
        }
        total.push_back(s + total.back());
    }
    /*cout << "create complete \n";
    cout << "total is ";
    for(auto x: total){
        cout << x << " ";
    }
    cout << endl;*/
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    int s;
    vector<int> total;

    int n,m;
    cin >> n >> m >> s;
    for(int i = 0; i < n; i++){
        int a,x;
        cin >> a >> x;
        q.push(make_pair(a,x));
    }

    for(int i = 0; i < m; i++){
        int p,x;
        cin >> p >> x;
        createMoreTotal(total,q,s,p);
        auto it = lower_bound(total.begin(),total.end(),p);
        if (x >= (it - total.begin())) cout << it - total.begin()<< " ";
        else {
            p += total[x];
            //cout << "p equal " << p << endl;
            createMoreTotal(total,q,s,p);
            cout << lower_bound(total.begin(),total.end(),p) - total.begin()<< " ";
        }
    }

    return 0;
}
