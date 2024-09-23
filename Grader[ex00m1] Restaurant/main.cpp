#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    int Ti[N];
    vector<int> v;
    v.resize(N);
    for (int i = 0; i < N; i++){
        cin >> Ti[i];
    }
    for(int i = 0; i < N && i < M; i++){
        v[i] = Ti[i];
        cout << "0 \n";
    }
    for(int i = N; i < M; i++){
        auto it = min_element(v.begin(),v.end());
        cout << *it << "\n";
        *it += Ti[(it - v.begin())];
    }
    return 0;
}
