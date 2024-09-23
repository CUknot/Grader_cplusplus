#include <iostream>
#include <algorithm>

using namespace std;

int n,k;

int func(int s, int budget, int* arr, int* sum, int* tofind){
    int distance = upper_bound(tofind,tofind + n + 1,budget + tofind[s]) - tofind;
    return sum[distance - 1] - sum[s];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m;
    cin >> n >> m >> k;

    int arr[n];
    int sum[n + 1];
    int tofind[n+1];
    sum[0] = 0;
    tofind[0] = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i + 1] = sum[i] + arr[i];
        tofind[i + 1] = tofind[i] + arr[i] + k;
    }

    int x, budget;
    for(int i = 0; i < m; i++){
        cin >> x >> budget;
        cout << func(x,budget,arr,sum,tofind) << "\n";
    }

    return 0;
}
