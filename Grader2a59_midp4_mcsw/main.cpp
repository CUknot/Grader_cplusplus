#include <iostream>

using namespace std;

void fix(int &pre,int &count,int i,int k,int* arr){
    int tpre = 0; pre = 0;
    int tcount = 0; count = 0;
    for(int j = 0; j < k-1; j++){
        tcount++;
        tpre += arr[i-j];
        if(tpre > pre) {pre = tpre; count = tcount;}
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int pre = 0, count = 0;
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(pre + arr[i]> max) max = pre + arr[i];
        pre += arr[i];
        count++;
        if(pre < 0){pre = 0; count = 0;}
        if(count >= k) fix(pre,count,i,k,arr);
    }
    cout << max;
    return 0;
}

