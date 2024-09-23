#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
typedef pair<int,long long> pill;
typedef long long ll;

ll Prim(vector<ll> &v){
    vector<bool> visited(n,false);
    priority_queue<pill> q;
    q.push({0,0});
    ll total = 0;
    while(!q.empty()){
        int u = q.top().second;
        ll current_beauti = q.top().first;
        q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        total += current_beauti;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                q.push({v[u]^v[i],i});
            }
        }
    }
    return total;
}

int main()
{
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    cout << Prim(v);
    return 0;
}
