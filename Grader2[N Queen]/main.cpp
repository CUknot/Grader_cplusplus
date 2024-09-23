#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
int N;

bool check(pii xy, vector<int> &v){
    for(int i = 0; i < N; i++){
        if(abs(i - xy.first) == abs(v[i] - xy.second) ||
            xy.second == v[i])
            return false;
    }
    return true;
}

int dfs(int idx, vector<int> &v){
    if(idx == N) return 1;
    int temp = 0;
    for(int i = 0; i < N; i++){
        if(check({idx,i}, v)) {
            v[idx] = i;
            temp += dfs(idx + 1, v);
            v[idx] = 2e9;
        }
    }
    return temp;
}
int main()
{
    cin >> N;
    vector<int> v(N, 2e9);
    cout << dfs(0,v) << endl;
    return 0;
}
