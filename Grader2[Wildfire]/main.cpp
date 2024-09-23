#include <iostream>
#include <vector>

using namespace std;

void afterFlame(int n, int* beauty, vector<vector<int>> &adjacencyList, int &total){
    if(beauty[n] == -1) return;
    total -= beauty[n];
    beauty[n] = -1;
    for(auto x: adjacencyList[n]) afterFlame(x,beauty,adjacencyList,total);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    int total = 0;
    int beauty[n], flame[k];
    vector<vector<int>> adjacencyList(n);
    for(int i = 0; i < n; i++){
        cin >> beauty[i];
        total += beauty[i];
    }
    for(int i = 0; i < k; i++){
        cin >> flame[i];
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adjacencyList[x].push_back(y);
    }

    for(int i = 0; i < k; i++){
        afterFlame(flame[i],beauty,adjacencyList,total);
        cout << total << " ";
    }
    return 0;
}
