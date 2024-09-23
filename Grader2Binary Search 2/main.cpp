#include <iostream>

using namespace std;

int rec(int begin, int end,const int &x, int* arr){
    if(arr[begin] > x) return -1;
    if (end - begin > 1){
        int temp = rec((begin+end)/2,end,x,arr);
        if(temp != -1) return temp;
        else return rec(begin,(begin+end)/2,x,arr);
    }
    else if(arr[begin] <= x) return begin;
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
    int temp,in;
    for(int i = 0; i < M; i++){
        cin >> in;
        temp = rec(0,N,in,arr);
        if (temp == -1) cout << "-1 \n";
        else cout << arr[temp] << "\n";
    }
    return 0;
}
