#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int N, M, L, input1;
    string input2;
    vector<int> v1;
    vector<string> v2;
    cin >> N >> M >> L;
    while(L--){
        cin >> input1;
        v1.push_back(input1);
    }
    while(N--){
        cin >> input2;
        v2.push_back(input2);
    }
    set<string> s(v2.begin(),v2.end());
    while(M--){
        cin >> input2;
        vector<char> charVector(input2.begin(), input2.end());
        for (int i = 0; i < charVector.size(); i++) {
            charVector[i] = 'a' + ((charVector[i] - 'a' + v1[i]) % 26);
        }
        string word(charVector.begin(),charVector.end());
        if (s.find(word) != s.end()){
            cout << "Match\n";
        }
        else{
            cout << "Unknown\n";
        }
    }
    return 0;
}
