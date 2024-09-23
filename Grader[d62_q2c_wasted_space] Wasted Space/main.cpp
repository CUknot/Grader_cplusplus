#include <iostream>

using namespace std;

int main()
{
    int input;
    cin >> input;
    int p = 1;
    while(p < input){
        p *= 2;
    }
    cout << p - input << "\n";
    return 0;
}
