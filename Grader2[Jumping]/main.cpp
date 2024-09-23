#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,temp;
    cin >> n;
    vector<int> v(n + 2,0);
    cin >> temp;
    for(int i = 0; i < n - 1; i++)cin >> v[i + 3];

    for(int i = 0; i < n; i++) v[i + 3] += *max_element(v.begin() + i, v.begin() + i + 3);

    /*for(int i = 0; i < n + 2; i++) cout << v[i] << " ";
    cout << endl;*/

    cout << v.back();
    return 0;
}
