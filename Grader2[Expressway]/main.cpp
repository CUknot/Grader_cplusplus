#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Floyd-Warshall
    int nyear;
    cin >> nyear;
    vector<vector<int>> v1(nyear, vector<int> (nyear,2e9));
    vector<vector<int>> v2(nyear, vector<int> (nyear));

    v1[0][0] = 0;
    cin >> v1[0][1];
    v1[1][0] = v1[0][1];
    v1[1][1] = 0;
    for(int y = 2; y < nyear; y++){
        v1[y][y] = 0;
        int namount;
        cin >> namount;
        for(int i = 0; i < namount; i++){
            int a,w;
            cin >> a >> w;
            v1[y][a - 1] = w;
            v1[a - 1][y] = w;
        }
    }
    /*for(auto row: v1){
        for(auto x: row) cout << x << " ";
        cout << endl;
    }*/
    for(int y = 0; y < nyear; y++){
        for(int i = 0; i < nyear; i++){
            for(int j = 0; j < nyear; j++){
                if(v1[i][y] == 2e9 || v1[y][i] == 2e9) v2[i][j] = v1[i][j];
                else v2[i][j] = min(v1[i][j], v1[i][y] + v1[y][j]);
            }
        }
        if(y >= 2) cout << v2[0][1] << " ";
        swap(v1,v2);
    }

    return 0;
}
