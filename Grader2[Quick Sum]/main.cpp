#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int nrow, ncol, nans;
    cin >> nrow >> ncol >> nans;
    int arr[nrow + 1][ncol + 1];

    int temp;
    for(int i = 0; i < nrow; i++){
        for(int j = 0; j < ncol; j++){
            cin >> temp;
            if(i == 0 && j == 0) arr[0][0] = temp;
            else if(i == 0) arr[0][j] = arr[0][j - 1] + temp;
            else if(j == 0) arr[i][0] = arr[i - 1][0] + temp;
            else arr[i][j] = arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1] + temp;
        }
    }

    /*for(int i = 0; i < nrow; i++){
        for(int j = 0; j < ncol; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/
    int x1,x2,y1,y2;
    for(int i = 0; i < nans; i++){
        cin >> y1 >> x1 >> y2 >> x2;
        int ans = arr[y2][x2];
        if (y1 > 0) ans -= arr[y1 - 1][x2];
        if (x1 > 0) ans -= arr[y2][x1 - 1];
        if (y1 > 0 && x1 > 0) ans += arr[y1 - 1][x1 - 1];
        cout << ans << "\n";
    }
    return 0;
}
