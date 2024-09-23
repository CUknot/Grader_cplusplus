#include <iostream>

using namespace std;

int main()
{
    const int MOD = 1997;
    int n, k;
    cin >> n >> k;
    int arr[k + 1][n + 1];

    //for(int i = 0; i <= k; i++) arr[i][0] = 0;
    for(int i = 1; i <= n; i++) arr[0][i] = 0;
    arr[1][1] = 1;
    for(int i = 2; i <= k; i++) arr[i][1] = 0;

    for(int x = 2; x <= n; x++){
        for(int y = 1; y <= k; y++){
            arr[y][x] = (arr[y-1][x-1] + y * arr[y][x-1]) % MOD;
        }
    }

    cout << arr[k][n];
    return 0;
}
