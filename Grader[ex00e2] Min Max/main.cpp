#include <iostream>

using namespace std;

int main()
{
    int N,M,times;
    cin >> N >> M;
    cin >> times;
    int A[N][M] ;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }
    int region[times][4];
    for (int i = 0; i < times; i++){
        cin >> region[i][0] >> region[i][1] >> region[i][2] >> region[i][3];
    }
    for (int i = 0; i < times; i++){
        if ((region[i][0]) > (region[i][2]) || (region[i][1]) > (region[i][3])){
            cout << "INVALID" << endl;
            continue;
        }
        if (((region[i][0]) > N ) || ((region[i][1]) > M ) || ((region[i][2]) <= 0 ) || ((region[i][3]) <= 0 )){
            cout << "OUTSIDE" << endl;
            continue;
        }
        if ((region[i][0]) < 1){
            (region[i][0]) = 1;
        }
        if ((region[i][1]) < 1){
            (region[i][1]) = 1;
        }
        if ((region[i][2]) > N){
            (region[i][2]) = N;
        }
        if ((region[i][3]) > M){
            (region[i][3]) = M;
        }
        int max = A[region[i][0] - 1][region[i][1] - 1];
        for (int x = (region[i][0]); x <= (region[i][2]); x++){
            for (int y = (region[i][1]); y <= (region[i][3]); y++){
                if (max < A[x - 1][y - 1]){
                    max = A[x - 1][y - 1];
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}
