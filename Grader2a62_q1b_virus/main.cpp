#include <iostream>

using namespace std;

bool rec(int begin, int end, int k, bool* arr){
    if(k > 1){
        if (!rec((begin + end + (begin < end))/2, end, k - 1, arr)) return false;
        return rec(begin, (begin + end + (begin > end))/2, k - 1, arr) || rec((begin + end + (begin > end))/2, begin ,k - 1, arr);
    }
    else{
        return arr[begin] == 0 && arr[end] == 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,tpk;
    cin >> n >> k;
    tpk = 1;
    for(int i = 0; i < k; i++) tpk *= 2;
    bool arr[tpk];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < tpk; j++){
            cin >> arr[j];
        }
        if(rec(0,tpk-1,k,arr)) cout << "yes \n";
        else cout << "no \n";
    }
    return 0;
}
