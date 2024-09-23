#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void findMedian(vector<int> &v){
    int size = v.size();

    // Calculate the index of the median
    int medianIndex = size / 2;

    // Use nth_element to rearrange elements such that the median is in its correct position
    nth_element(v.begin(), v.begin() + medianIndex, v.end());

    // Output the median
    cout << v[medianIndex] << " ";
}
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,w,input;
    vector<int> v;
    cin >> n >> w;// w is even
    for(int i = 0; i < n; i++){
        cin >> input;
        v.push_back(input);
    }
    if (n <= w){
        findMedian(v);
    }
    else{
        for(auto it = v.begin(); it != v.end() - w; it++){
            vector<int> v1(it,it + w + 1);
            findMedian(v1);
        }
    }
    return 0;
}
