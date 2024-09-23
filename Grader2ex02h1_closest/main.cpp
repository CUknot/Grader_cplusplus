#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // Add this header for sqrt function

using namespace std;

bool compareY(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int getDistance(pair<int,int> c1, pair<int,int> c2){
    return pow(c1.first - c2.first, 2) + pow(c1.second - c2.second, 2);
}

int getCloset(int begin, int size, pair<int,int>* arr){
    if(size > 3){
        int medianX = arr[begin + size/2].first;
        int m = min(getCloset(begin,size/2,arr),getCloset(begin + size/2,(size+1)/2,arr));

        vector<pair<int,int>> potential;
        for(int i = 0; i < size; i++){
            if(pow(medianX - arr[begin + i].first,2) < m) potential.push_back(arr[begin + i]);
        }
        nth_element(potential.begin(),potential.begin() + potential.size()/2,potential.end(),compareY);

        int medianY = potential[potential.size()/2].second;

        vector<pair<int,int>> potential2;
        for (auto p: potential){
            if(pow(medianY - p.second,2) < m) potential2.push_back(p);
        }
        //bruteforce potential2
        for(auto i = 0; i < potential2.size(); i++){
             for(auto j = i + 1; j < potential2.size(); j++){
                if(getDistance(potential2[i],potential2[j]) < m) m = getDistance(potential2[i],potential2[j]);
            }
        }
        return m;
    }
    else if(size == 3){
        int m = min(getDistance(arr[begin],arr[begin + 1]),getDistance(arr[begin],arr[begin + 2]));
        if (getDistance(arr[begin + 1],arr[begin + 2]) < m) m = getDistance(arr[begin + 1],arr[begin + 2]);
        return m;
    }
    else if(size == 2){
        return getDistance(arr[begin],arr[begin + 1]);
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    pair<int,int> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr,arr + n);
    cout << getCloset(0,n,arr) << endl;
    return 0;
}
