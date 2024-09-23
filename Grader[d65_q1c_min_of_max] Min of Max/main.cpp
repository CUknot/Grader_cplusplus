#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(m, 1);

    int firstLine[n];
    for (int i = 0; i < n; i++) {
        cin >> firstLine[i];
    }

    multiset<int> Less;
    for (int i = 0; i < m; ++i) {
        Less.insert(1);
    }

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (v[input] < firstLine[i]) {
            auto it = Less.find(v[input]);
            if (it != Less.end()) {
                Less.erase(it);
            }
            v[input] = firstLine[i];
            Less.insert(v[input]);
        }
        /*cout << "Less has " << endl;
        for (auto x: Less){
            cout << x << " ";
        }cout << endl;*/
        cout << *Less.begin() << " ";
    }
    return 0;
}
