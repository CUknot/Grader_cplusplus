#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int nrow, ncol;
    cin >> nrow >> ncol;

    int maxSquare = 0;
    int arr[nrow][ncol];
    string temp;
    cin >> temp;
    for(int j = 0; j < ncol; j++){
        arr[0][j] = (temp[j] == '1');
        if(arr[0][j] > maxSquare) maxSquare = arr[0][j];
    }
    for(int i = 1; i < nrow; i++){
        cin >> temp;
        arr[i][0] = (temp[0] == '1');
        if(arr[i][0] > maxSquare) maxSquare = arr[i][0];
        for(int j = 1; j < ncol; j++){
            arr[i][j] = (min({arr[i-1][j-1],arr[i-1][j],arr[i][j-1]}) + 1) * (temp[j] == '1');
            if(arr[i][j] > maxSquare) maxSquare = arr[i][j];
        }
    }
    /*for(int i = 0; i < nrow; i++){
        for(int j = 0; j < ncol; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << maxSquare << endl;
    return 0;
}
