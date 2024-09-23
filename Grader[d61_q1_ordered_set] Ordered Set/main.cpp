#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v = A;
    set<T> sa(A.begin(),A.end());
    for (auto x: B){
        if(sa.find(x) == sa.end()) v.push_back(x);
    }
    return v;
}

template <typename T>
    vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<pair<int,T>> temp;
    vector<T> v;
    map<T,int> m;
    for (int i = 0; i < A.size(); i++){
        m[A[i]] = i;
    }
    for (auto x: B){
        if(m.find(x) != m.end()) temp.push_back(make_pair(m[x],x));
    }
    sort(temp.begin(),temp.end());
    for (auto x: temp) v.push_back(x.second);
    return v;
}
