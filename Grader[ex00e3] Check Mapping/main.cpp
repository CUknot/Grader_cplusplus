#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N, input;
    string output = "YES";
    set<int> s;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        s.insert(input);
    }
    for (int i = 1; i <= N; i++) {
        if (s.count(i) == 0) {
            output = "NO";
            break;
        }
    }
    cout << output << endl;
    return 0;
}
