#include <iostream>

using namespace std;

bool similarStr(string a, string b){
    long long length = a.length();
    if(length == 1) return a == b;
    else{
        return (similarStr(a.substr(0, length / 2), b.substr(0, length / 2)) &&
                similarStr(a.substr(length / 2, length / 2), b.substr(length / 2, length / 2))) ||
               (similarStr(a.substr(0, length / 2), b.substr(length / 2, length / 2)) &&
                similarStr(a.substr(length / 2, length / 2), b.substr(0, length / 2)));
    }
}

int main()
{
    string a,b;
    cin >> a >> b;
    if(similarStr(a, b)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
