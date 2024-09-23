#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int input[n], sortInput[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
        sortInput[i] = input[i];
    }
    sort(sortInput, sortInput + n);

    int arr[n+1][n+1];
    for (int i = 0; i <= n; i++) arr[i][0] = 0;
    for (int j = 0; j <= n; j++) arr[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (input[i - 1] == sortInput[j - 1]) arr[i][j] = arr[i - 1][j - 1] + 1;
            else {
                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
            }
        }
    }
    cout << arr[n][n];
    return 0;
}
