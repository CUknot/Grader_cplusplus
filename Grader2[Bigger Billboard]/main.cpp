#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    if(n > 3){
        cin >> arr[0];
        cin >> arr[1];
        cin >> arr[2];
        int temp;
        cin >> temp;
        arr[3] = max({arr[2], arr[1], arr[0] + temp});
        for(int i = 4; i < n; i++){
            cin >> temp;
            arr[i] = max({arr[i-1], arr[i-2], arr[i-3] + temp, arr[i - 4] + temp});
        }
        //for(auto i = 0; i < n;i++) cout << arr[i] << " ";
        cout << max({arr[n-1], arr[n-2],arr[n-3],arr[n-4]}) << "\n";
    }
    else cout << *max_element(arr,arr + n) << "\n";
    return 0;
}
