#include <iostream>

using namespace std;

int main()
{
    const int MOD = 100000007;
    long long N;
    cin >> N;
    //state 0 end with "00"
    //state 1 end with "01"
    //state 2 end with "10"
    //state 3 end with "11"

    long long last[4];
    long long now[4];
    for(long long i = 0; i < 4; i++) last[i] = 1;
    for(long long i = 3; i <= N; i++){
        now[0] = (last[0] + last[2]) % MOD;
        now[1] = (last[0]) % MOD;
        now[2] = (last[1] + last[3]) % MOD;
        now[3] = (last[1] + last[3]) % MOD;
        for(long long i = 0; i < 4; i++) last[i] = now[i];
    }
    /*for(int i = 0; i < 4; i++){
        for(int j = 0; j <= N; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << (now[0] + now[1] + now[2] + now[3]) % MOD << endl;
    return 0;
}
