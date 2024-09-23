#include <iostream>
#include <math.h>

using namespace std;

int len(int n) {
    int length = 0;
    while (n != 0) {
        n /= 10;
        length++;
    }
    return length;
}

int generateOnes(int n) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result = result * 10 + 1;
    }
    return result;
}

int myDC(int n, int len, bool inversed) {
    if (len > 1) {
        int ones = generateOnes(len);
        if (inversed) {
            return n / ones * len + myDC(n - n / ones * ones, len - 1, false);
        } else {
            return min(len + 1 + myDC(generateOnes(len + 1) - n, len, true), n / ones * len + myDC(n - n / ones * ones, len - 1, false));
        }
    } else {
        // Base case
        return min(n, 2 + 11 - n);
    }
}

int main()
{
    int input;
    cin >> input;
    cout << myDC(input, len(input), false) << endl;
    return 0;
}
