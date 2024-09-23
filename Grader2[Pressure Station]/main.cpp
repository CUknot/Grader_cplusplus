#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;

    int minimalSummation = 2e9;
    if(n <= k + 1){
        int temp;
        for(int i = 0; i < n; i++){
            cin >> temp;
            if(temp < minimalSummation) minimalSummation = temp;
        }
    }
    else{
        int arr[n];
        for(int i = 0; i < k + 1; i++) cin >> arr[i];
        for(int i = k + 1; i < n; i++){
            int temp;
            cin >> temp;
            arr[i] = *min_element(arr + max(i - 2 * k - 1, 0), arr + i) + temp;
        }
        minimalSummation = *min_element(arr + n - k - 1, arr + n);
        //for(int i = 0; i < n; i++) cout << arr[i] << " ";
    }
    cout << minimalSummation << endl;
    return 0;
}
