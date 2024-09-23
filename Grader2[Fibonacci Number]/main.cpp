#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 1) {cout << "1\n"; return 0;}
    else if(n == 2) {cout << "1\n"; return 0;}
    int fn = 1;
    int fn1 = 1;
    int fn2 = 0;
    for(int i = 2; i < n; i++){
        fn2 = fn1;
        fn1 = fn;
        fn = fn1 + fn2;
    }
    cout << fn << endl;
    return 0;
}
