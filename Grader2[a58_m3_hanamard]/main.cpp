#include <iostream>
#include <vector>

using namespace std;

void hana(int nsize, int idx , int* vec, vector<int> &v){
    if(nsize > 1){
        vector<int> left, right;
        hana(nsize/2, idx, vec, left);
        hana(nsize/2, idx + nsize/2, vec, right);
        v.resize(nsize);
        for(int i = 0; i < nsize/2; i++) v[i] = left[i] + right[i];
        for(int i = 0; i < nsize/2; i++) v[nsize/2 + i] = left[i] - right[i];
    }
    else{
        v.resize(1);
        v[0] = vec[idx];
    }

}

int main()
{
    int nsize;
    cin >> nsize;
    int vec[nsize];
    vector<int> out;
    out.reserve(nsize); // Reserve space to avoid reallocations
    for(auto i = 0; i < nsize; i++) cin >> vec[i];

    hana(nsize, 0 , vec, out);
    for(auto i = 0; i < nsize; i++) cout << out[i] << " ";
    return 0;
}
