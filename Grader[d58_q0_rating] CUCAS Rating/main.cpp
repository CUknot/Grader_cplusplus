#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

float mean(vector<int> v);

int main()
{
    cout << std::fixed << std::setprecision(2);
    int N, score;
    string id, name;
    map<string,vector<int>> m1;
    map<string,vector<int>> m2;
    cin >> N;
    while(N--){
        cin >> id >> name >> score;
        m1[id].push_back(score);
        m2[name].push_back(score);
    }
    for(auto x: m1){
        cout << x.first << " " << mean(x.second) << "\n";
    }
    for(auto x: m2){
        cout << x.first << " " << mean(x.second) << "\n";
    }
    return 0;
}

float mean(vector<int> v){
    float sum;
    for (auto x: v){
        sum += x;
    }
    return sum / v.size();
}
