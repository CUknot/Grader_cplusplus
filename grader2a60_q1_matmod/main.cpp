#include <iostream>
#include <vector>

using namespace std;

int K;

vector<int> mul(vector<int> a, vector<int> b){
  vector<int> temp(4);
  temp[0] = ((a[0] * b[0]) % K + (a[1] * b[2]) % K) % K;
  temp[1] = ((a[0] * b[1]) % K + (a[1] * b[3]) % K) % K;
  temp[2] = ((a[2] * b[0]) % K + (a[3] * b[2]) % K) % K;
  temp[3] = ((a[2] * b[1]) % K + (a[3] * b[3]) % K) % K;
  return temp;
}
vector<int> modpow(vector<int> X,int N){
    if (N == 1) return X;
    else if(N % 2 == 0){
        vector<int> temp = modpow(X,N/2);
        return mul(temp,temp);
    }
    else {
        vector<int> temp = modpow(X,N/2);
        return mul(X, mul(temp,temp));
    }
}
int main() {
    // Write C code here
    vector<int> X(4);
    int N;
    cin >> N >> K;
    for(int i = 0; i < 4; i++) {
      int temp;
      cin >> temp;
      X[i] = temp % K;
    }
    vector<int> temp = modpow(X,N);
    for(int i = 0; i < 4; i++) cout << temp[i] << " ";
    return 0;
}
