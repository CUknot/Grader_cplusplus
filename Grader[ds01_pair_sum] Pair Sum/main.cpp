#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N, M, input;
    map<int, int> m;
    vector<string> output;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> input;
        m[input]++;
    }

    for (int i = 0; i < M; i++) {
        cin >> input;
        bool found = false;

        for (auto it = m.begin(); it != m.end(); it++) {
            if (m.find(input - (it->first)) != m.end()) {
                if(input - (it->first) == it->first){
                    if(m[it->first] >= 2){
                        found = true;
                        break;
                    }
                    else{
                        continue;
                    }
                }
                found = true;
                break;
            }
        }

        if (found) {
            output.push_back("YES");
        } else {
            output.push_back("NO");
        }
    }

    // Print the output
    for (string result : output) {
        cout << result << "\n";
    }

    return 0;
}

