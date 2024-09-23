#include <iostream>

using namespace std;

int main()
{
    int h,m;
    int X;
    cin >> h >> m;
    cin >> X;
    h = (h + (m + X)/60)%24;
    m = (m + X)%60;
    cout << ((h < 10)?"0":("")) << h << " " << ((m < 10)?"0":("")) << m << endl;
    return 0;
}
