#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int n, m, input1, input2;
    map<long long int, long long int> data;
    vector<string> output;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input1 >> input2;
        data[input2] = input1;
    }
    for (int i = 0; i < m; i++) {
        cin >> input1 >> input2;
        if (input1 != input2 && data.find(input1) != data.end() && data.find(input2) != data.end()) {
            if (data.find(data[input1]) != data.end() && data.find(data[input2]) != data.end()) {
                if (data[data[input1]] == data[data[input2]]) {
                    output.push_back("YES");
                    continue;
                }
            }
        }
        output.push_back("NO");
    }
    for (string x : output) {
        cout << x << endl;
    }
    return 0;
}
