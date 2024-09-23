#include <iostream>

using namespace std;

int len(long long n) {
    if (n <= 1) return 1;
    return 2 * len(n / 2) + 1;
}

long long numberOne(long long n, long long s, long long e) {
    if (n > 1) {
        long long size = len(n);
        long long mid = size / 2 + 1;
        long long temp = 0;

        if (s < mid) temp += numberOne(n / 2, s, min(e, mid - 1));
        if (s <= mid && e >= mid) temp += n % 2;
        if (e > mid) temp += numberOne(n / 2, max(1LL, s - mid), e - mid);

        return temp;
    } else {
        return n;
    }
}

int main() {
    long long n, s, e;
    cin >> n >> s >> e;
    cout << numberOne(n, s, e);
    return 0;
}
