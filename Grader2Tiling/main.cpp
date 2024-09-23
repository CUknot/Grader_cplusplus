#include <iostream>

using namespace std;

int findQuadrant(int size, int x, int y){
    int out = 0;
    if (x >= size/2) out += 1;
    if (y >= size/2) out += 2;
    return out;
}

void printTile(int size, int x, int y, int type){
    if(type == -1) return ;
    if(size > 2){
        int arr[4] = {3,2,1,0};
        arr[type] = -1;
        printTile(size/2, x, y, arr[0]);
        printTile(size/2, x + size/2, y, arr[1]);
        printTile(size/2, x, y + size/2, arr[2]);
        printTile(size/2, x + size/2, y + size/2, arr[3]);
        printTile(size/2, x + size/4, y + size/4, type);

    }
    else cout << type << " " << x << " " << y << "\n";
}
void rec(int size, int x, int y, int misx, int misy){
    if(size > 1){
        int type = findQuadrant(size, misx-x, misy-y);
        printTile(size, x, y, type);
        if(type%2) x += size/2;
        if(type>=2) y += size/2;
        rec(size/2, x, y, misx, misy);
    }
}
int main()
{
    int L,X,Y;
    cin >> L >> X >> Y;
    cout << (L*L-1)/3 << " \n";
    rec(L,0,0,X,Y);
    return 0;
}
