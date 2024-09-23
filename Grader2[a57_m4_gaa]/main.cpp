#include <iostream>

using namespace std;

int input;
bool out = 0;
int total = 1;

void recure(int n){
    if(n > 1 && total <= input) {
        recure(n-1);
        total += n + 3;
        if(total == input) out = 1;
        recure(n-1);
    }
    else if(n == 1 && total <= input){
        total += 3;
        if(total == input) out = 1;
        total += 4;
        if(total == input) out = 1;
        total += 3;
        if(total == input) out = 1;
    }
}

int main()
{
    cin >> input;
    if(input == 1) {cout << "g"; return 0;}
    int n = 1;
    while(total <= input) {
        total = 1;
        recure(n);
        n++;
    }
    if(out) cout << "g";
    else cout << "a";
}
