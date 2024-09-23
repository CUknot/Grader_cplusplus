#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mem;

int TD(int n, vector<int> &v){
    if(n == 0) return 0;
    if(mem[n] != -2) return mem[n];
    int maxcut = -1;
    for(auto x: v) {
        if(n - x >= 0){
            int temp = TD(n - x,v);
            if(temp != -1 && maxcut < temp + 1){
                maxcut = temp + 1;
            }
        }
    }
    mem[n] = maxcut;
    return maxcut;
}

int main()
{
    int n;
    cin >> n ;
    vector<int> v(3);
    mem = vector<int>(n + 1, -2);
    mem[0] = 0;
    for(int i = 0; i < 3; i++) cin >> v[i];

    /*for(int i = 0; i < 3; i++) cout << v[i] << " ";
    cout <<endl;*/
    cout << TD(n, v) << "\n";
    //for(int i = 0; i < n + 1; i++) cout << mem[i];
    return 0;
}
