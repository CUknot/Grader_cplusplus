#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,K,m;
    cin >> n >> K >> m;
    int total[n + 1];
    int temp;
    total[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> temp;
        total[i] = temp - m + total[i-1];
    }
    /*for(int i = 0; i <= n; i++) cout << total[i] << " ";
    cout << "\n";*/
    int start, want;
    for(int i = 0; i < K; i++){
        cin >> start >> want;
        int distant = lower_bound(total, total + n, total[start - 1] + want) - total;
        cout << distant << "\n";
    }
    return 0;
}
