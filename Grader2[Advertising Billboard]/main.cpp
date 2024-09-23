#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    if(n > 2){
        cin >> arr[0];
        cin >> arr[1];
        int temp;
        cin >> temp;
        arr[2] = max(arr[1], arr[0] + temp);
        for(int i = 3; i < n; i++){
            cin >> temp;
            arr[i] = max({arr[i-1], arr[i-2] + temp,arr[i-3] + temp});
        }
        cout << max({arr[n-1], arr[n-2],arr[n-3]}) << "\n";
    }
    else cout << *max_element(arr,arr + n) << "\n";
    return 0;
}
