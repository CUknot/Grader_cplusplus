#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int N;

int recur(int idx, int current){
    if(current == N) return 1;
    if(idx == 0) return 0;
    int temp = 0;
    temp += recur(idx - 1, current);
    while(current + idx <= N){
        current += idx;
        temp += recur(idx - 1, current);
    }
    return temp;
}

int main()
{
    cin >> N;
    cout << recur(N,0) << endl;
    return 0;
}
