#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<pair<int,int>,pair<int,int>> wkxy;

int R,C;
void Prim(vector<vector<int>> &G, vector<vector<int>> &ans){
    const int dx[] = {1,-1,0,0,2,-2,0,0,1,1,-1,-1,0};
    const int dy[] = {0,0,1,-1,0,0,2,-2,1,-1,1,-1,0};
    vector<vector<vector<bool>>> visited(3, vector<vector<bool>>(R,vector<bool>(C,false)));
    priority_queue<wkxy,vector<wkxy>,greater<wkxy>> q;
    q.push({{0,0},{0,0}});

    while(!q.empty()){
        int x = q.top().second.first;
        int y = q.top().second.second;
        int w = q.top().first.first;
        int k = q.top().first.second;
        q.pop();

        if(visited[k][y][x]) continue;
        visited[k][y][x] = true;
        if(k == 2) ans[y][x] = w;

        for(int i = 0; i < 13; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < C && ny >= 0&& ny < R && !visited[k][ny][nx]) {
                if(i < 4) q.push({{w + G[ny][nx],k},{nx,ny}}); // move
                if(k < 2) q.push({{w ,k + 1},{nx,ny}}); //use Tear
            }
        }

    }
}

int main()
{
    cin >> R >> C;
    vector<vector<int>> G(R,vector<int>(C));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) cin >> G[i][j];
    }
    vector<vector<int>> ans(R,vector<int>(C,2e9));
    Prim(G,ans);
    for(auto x: ans){
        for(auto a: x) cout << a << " ";
        cout << "\n";
    }
    return 0;
}
