#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R,C;
vector<vector<int>> pandemic;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int c = 0;

void bfs(vector<pair<int,int>> &v, int day, vector<vector<bool>> &visited){
    queue<pair<int,int>> q1,q2;
    for(auto a: v) q1.push(a);
    while(day != 0){
        while(!q1.empty()){
            pair<int,int> temp = q1.front();
            q1.pop();
            if(!visited[temp.first][temp.second]){
                visited[temp.first][temp.second] = true;
                for(int i = 0; i < 4; i++) {
                    if(temp.first + dy[i] >= 0 && temp.first + dy[i] < R && temp.second + dx[i] >= 0 && temp.second + dx[i] < C &&
                       pandemic[temp.first + dy[i]][temp.second + dx[i]] == 0 && visited[temp.first + dy[i]][temp.second + dx[i]] == false){
                        pandemic[temp.first + dy[i]][temp.second + dx[i]] = 1;
                        c++;
                        q2.push({temp.first + dy[i],temp.second + dx[i]});
                       }
                }
            }
        }
        q1 = q2;
        q2 = queue<pair<int,int>>();
        day--;
    }
}

int main()
{
    int day;
    cin >> R >> C >> day;
    pandemic.resize(R,vector<int>(C));
    vector<vector<bool>> visited(R,vector<bool>(C,false));
    vector<pair<int,int>> v;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> pandemic[i][j];
            if(pandemic[i][j] == 1) {
                v.push_back({i,j});
                c++;
            }
        }
    }
    bfs(v,day,visited);
    /*for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) cout << pandemic[i][j] << " ";
        cout << "\n";
    }*/
    cout << c;
    return 0;
}
