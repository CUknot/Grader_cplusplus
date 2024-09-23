#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(2*n-1);

    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> temp;
            v[i - j + n - 1].push_back(temp);
        }
    }

    int prev;
    int maxsum = -INT_MAX;
    for(auto x: v){
        prev = 0;
        for(auto y: x){
            if(prev + y > maxsum) maxsum = prev + y;
            prev += y;
            if(prev < 0)prev = 0;
        }
    }

    cout << maxsum << "\n";
}
