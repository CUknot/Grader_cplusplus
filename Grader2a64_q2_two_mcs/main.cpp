#include <iostream>
#include <vector>

using namespace std;

vector<int> findm(int* arr, int n){
    vector<int> out(4);
    if(n <= 0) {out[0] = -1; return out;}
    out[1] = arr[0];
    int begin = 0;
    int pre = 0;
    for(int i = 0; i < n; i++){
        if(pre < 0) {pre = 0; begin = i;}
        if(pre + arr[i] > out[1]) {out[1] = pre + arr[i]; out[2] = begin; out[3] = i;}
        pre += arr[i];
    }
    return out;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    auto v1 = findm(arr,n);
    auto v2 = findm(arr,v1[2] - 1);
    auto v3 = findm(arr + v1[3] + 1, n - v1[3] - 1);

    /*for(auto x: v1)cout << x << " ";
    cout << "\n";
    for(auto x: v2)cout << x << " ";
    cout << "\n";
    for(auto x: v3)cout << x << " ";
    cout << "\n";*/

    cout << max(0,max(v2[1],v3[1])) + v1[1] << "\n";

    return 0;
}
