#include <iostream>

using namespace std;

int main()
{
    int nlevel;
    cin >> nlevel;
    int tri[nlevel][nlevel];
    for(int i = 0; i < nlevel; i++){
        for(int j = 0; j <= i; j++){
            cin >> tri[i][j];
        }
    }

    for(int i = nlevel - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            tri[i][j] += max(tri[i+1][j], tri[i+1][j+1]);
        }
    }

    /*for(int i = 0; i < nlevel; i++){
        for(int j = 0; j < nlevel; j++){
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << tri[0][0];
    return 0;
}
