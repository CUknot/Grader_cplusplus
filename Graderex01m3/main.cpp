#include <iostream>

using namespace std;
long long gettot(long long time, int N, int* arr){
    long long total = 0;
    for(int i = 0; i < N; i++){
        total += time/arr[i];
    }
    return total + N;
}

long long rec(long long begin,long long end,long long x,int N, int* arr) {
    if(gettot(end,N,arr) < x) return rec(end, 2*end, x, N, arr);
    if(end - begin > 1){
        long long temp = rec(begin,(begin + end)/2,x,N,arr);
        if(temp != -1) return temp;
        else return rec((begin + end)/2,end,x,N,arr);
    }
    else if(gettot(begin,N,arr) >= x){
        return begin;
    }
    else return -1;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,A;
    cin >> N >> A;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    long long temp;
    for(int i = 0; i < A; i++){
        cin >> temp;
        cout << rec(0,temp,temp,N,arr) << "\n";
    }
    return 0;
}
