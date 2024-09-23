#include <iostream>

using namespace std;

int main()
{
    int n, input;
    cin >> n;
    int tempMax = 0;
    int tempMin = 0;
    int max = -2e9;
    int min = 2e9;
    int total = 0;
    for(int i = 0; i < n; i++){
        cin >> input;
        total += input;

        if(tempMax < 0)tempMax = 0;
        tempMax += input;
        if(max < tempMax) max = tempMax;

        if(tempMin > 0)tempMin = 0;
        tempMin += input;
        if(min > tempMin) min = tempMin;
    }
    if(total == min)cout << max;
    else cout << std::max(max,total - min);
}
