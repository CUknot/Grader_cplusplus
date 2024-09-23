#include <iostream>
#include <vector>

using namespace std;

void dc(int x, int y, int a, int b, vector<vector<int>> &matrix){
    if(a > 0){
        dc(x, y, a - 1, b, matrix);
        dc(x + (1 << (a - 1)), y, a - 1, b - 1, matrix);
        dc(x, y + (1 << (a - 1)), a - 1, b + 1, matrix);
        dc(x + (1 << (a - 1)), y + (1 << (a - 1)), a - 1, b, matrix);

    }
    else{
        matrix[y][x] = b;
    }
}

int main()
{
    int a,b;
    cin >> a >> b;
    vector<vector<int>> matrix(1LL << a, vector<int>(1LL << a));
    dc(0,0,a,b,matrix);
    for(auto row: matrix){
        for(auto x: row){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
