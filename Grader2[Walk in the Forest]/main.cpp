#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int nrow, ncol;
    cin >> nrow >> ncol;
    int arr[nrow][ncol];

    int temp;
    //1st row
    cin >> arr[0][0];
    for(int j = 1; j < ncol; j++){
        cin >> temp;
        arr[0][j] = arr[0][j-1] + temp;
    }
    for(int i = 1; i < nrow; i++){
        cin >> temp;
        arr[i][0] = arr[i-1][0] + temp;
        for(int j = 1; j < ncol; j++){
            cin >> temp;
            arr[i][j] = max({arr[i-1][j], arr[i][j-1], (arr[i-1][j-1] + temp)}) + temp;
        }
    }

    /*for(int i = 0; i < nrow; i++){
        for(int j = 0; j < ncol; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << arr[nrow-1][ncol-1] << endl;
    return 0;
}
