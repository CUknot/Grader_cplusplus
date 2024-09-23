#include <iostream>

using namespace std;

int sum;

bool havesum(int* arr, int N){
    for(int idx = 0; idx < N; idx++){
        int min = 0;
        int max = N - 1;
        while(! (min == max || idx == min || idx == max) ){
            if(arr[min] + arr[max] == sum - arr[idx])return true;
            else if(arr[min] + arr[max] > sum - arr[idx]) max--;
            else if(arr[min] + arr[max] < sum - arr[idx]) min++;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,M;
    cin >> N >> M;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < M; i++){
        cin >> sum;
        if(havesum(arr,N)) cout << "YES \n";
        else cout << "NO \n";
    }
    return 0;
}
