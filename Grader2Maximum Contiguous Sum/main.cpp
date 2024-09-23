#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max = arr[0], currentSum = 0, cbegin = 0, begin = 0, cend = 0, end = 0;
    for (int i = 0; i < 2 * n; i++) {
        currentSum += arr[i % n];
        cend = (cend + 1) % n;
        if (max < currentSum) {
            max = currentSum;
            begin = cbegin;
            end = cend;
        }
        if (currentSum < 0) {
            currentSum = 0;
            cbegin = (i % n) + 1;
        }
        else if(cbegin == cend) break;
    }
    //cout << max << " " << begin << " " << end;
    cout << max;
    return 0;
}
