#include <iostream>
#include <string> // Include the <string> header for using string datatype

using namespace std;

int main() {
    string input1, input2;
    cin >> input1 >> input2;
    int size1 = input1.length();
    int size2 = input2.length();

    int arr[size1 + 1][size2 + 1];
    for (int i = 0; i <= size1; i++) arr[i][0] = 0;
    for (int j = 0; j <= size2; j++) arr[0][j] = 0;

    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            if (input1[i - 1] == input2[j - 1]) arr[i][j] = arr[i - 1][j - 1] + 1;
            else {
                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
            }
        }
    }
    cout << arr[size1][size2];
    return 0;
}
