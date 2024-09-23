#include <iostream>

using namespace std;

long long DC(int n, int k){
    if(n == k || k == 0) return 1;
    else{
        return DC(n-1,k) + DC(n-1,k-1);
    }
}

int main()
{
    int n,k;
    cin >> n >> k;
    cout << DC(n,k) << endl;
    return 0;
}
