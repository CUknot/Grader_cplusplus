#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Floyd-Warshall
    int nQ;
    cin >> nQ;
    for(int i = 0; i < nQ; i++){
        int ntable;
        cin >> ntable;
        vector<vector<float>> v(ntable,vector<float>(ntable));
        for(int y = 0; y < ntable; y++){
            for(int x = 0; x < ntable; x++){
                cin >> v[y][x];
            }
        }
        for(int k = 0; k < ntable; k++){
            for(int y = 0; y < ntable; y++){
                for(int x = 0; x < ntable; x++){
                    v[y][x] = max(v[y][x], v[y][k] * v[k][x]);
                }
            }
        }
        bool infiniteProfit = false;
        for(int i = 0; i < ntable; i++){
            if(v[i][i] != 1) {
                infiniteProfit = true;
                break;
            }
        }
        if(infiniteProfit) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
