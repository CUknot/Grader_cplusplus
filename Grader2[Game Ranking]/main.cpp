#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N,P;
    cin >> N >> P;
    vector<vector<int>> G(N);
    vector<int> InDegree(N,0);
    for(int i = 0; i < P; i++){
        int x,y;
        cin >> x >> y;
        G[y].push_back(x);
        InDegree[y]++;
    }
    vector<bool> visited(N,false);
    queue<int> q1,q2;
    int c = 0;
    for(int i = 0; i < N; i++) {
        if(InDegree[i] == 0) {
            q1.push(i);
            visited[i] = true;
        }
    }

    while(c != N){
        c += q1.size();
        cout << q1.size() << " ";
        while(!q1.empty()){
            int temp = q1.front();
            q1.pop();
            for(auto u : G[temp]){
                InDegree[u]--;
                if(!visited[u]){
                    q2.push(u);
                    visited[u] = true;
                }
            }
        }
        q1 = q2;
        q2 = queue<int>();
    }
    return 0;
}
