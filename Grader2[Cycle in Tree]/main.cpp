#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> level(n,-1);
    level[0] = 0;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        if(level[y] != -1) cout << level[x] + level[y] + 1;
        else level[y] = level[x] + 1;
    }
    return 0;
}
