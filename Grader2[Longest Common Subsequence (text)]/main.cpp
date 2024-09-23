#include <iostream>

using namespace std;

int main() {
    int size1, size2;
    string input1, input2;
    cin >> size1 >> size2;
    cin >> input1 >> input2;

    int arr[size1 + 1][size2 + 1];
    for (int i = 0; i < size1 + 1; i++) {
        for (int j = 0; j < size2 + 1; j++) {
            cin >> arr[i][j];
        }
    }

    string out = "";
    int y = size1;
    int x = size2;
    while (x > 0 && y > 0) {
        while (arr[y - 1][x] == arr[y][x] && y > 0) y--;
        while (arr[y][x - 1] == arr[y][x] && x > 0) x--;
        x--;
        y--;
        if (x >= 0 && y >= 0) out = input1[y] + out;
    }
    cout << out;
    return 0;
}
