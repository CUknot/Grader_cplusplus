#include <iostream>

using namespace std;

bool DIVOC = true;

int rec(int begin, int end, int k, int* arr){
    if(!DIVOC) return -1;
    if(k > 1){
        int left = rec(begin,(begin + end)/2, k-1, arr);
        int right = rec((begin + end)/2, end, k-1, arr);
        if(left - right == -1 || left - right == 0 || left - right == 1){
            return left + right;
        }
        else {
            DIVOC = false;
            return -1;
        }
    }
    else return arr[begin] + arr[begin + 1];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,tpk;
    cin >> n >> k;
    tpk = 1;
    for(int i = 0; i < k; i++) tpk *= 2;
    int arr[tpk];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < tpk; j++){
            cin >> arr[j];
        }
        DIVOC = true;
        rec(0, tpk, k, arr);
        if(DIVOC) cout << "yes \n";
        else cout << "no \n";
    }

    return 0;
}
