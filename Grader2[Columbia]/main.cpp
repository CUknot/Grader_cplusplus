#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R,C;
typedef pair<int,pair<int,int>> ixy;

void Prim(vector<vector<int>> &vfee, vector<vector<int>> &ans){
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    vector<vector<bool>> visited(R, vector<bool>(C,false));
    priority_queue<ixy,vector<ixy>,greater<ixy>> q;
    q.push({0,{0,0}});

    while(!q.empty()){
        int fee = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();

        if(visited[y][x]) continue;
        visited[y][x] = true;
        ans[y][x] = fee;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < C && 0 <= ny && ny < R && !visited[ny][nx]) q.push({fee + vfee[ny][nx],{nx,ny}});
        }
    }
}

int main()
{
    cin >> R >> C;

    vector<vector<int>> vfee(R, vector<int>(C));
    vector<vector<int>> ans(R, vector<int>(C));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> vfee[i][j];
        }
    }
    Prim(vfee,ans);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
