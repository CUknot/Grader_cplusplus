#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int data[N];
    for(int i = 0; i < N; ++i) cin >> data[i];

    int count = 0;
    for(int i = 0; i < N; ++i){
        for(int j = i + 1; j < N; ++j){
            if(data[i] > data[j]) count++;
        }
    }
    cout << count;
    return 0;
}
