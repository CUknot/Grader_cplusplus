/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int n;
vector<int> v;
vector<vector<int>> memo; // Memoization table

int DP(int idx, int m){
    if(idx == n) {
        return m == 0 ? 0 : -1; // Return 0 if successfully covered, otherwise -1
    }
    if (memo[idx][m] != -2) {
        return memo[idx][m]; // If the result is already calculated, return it
    }
    vector<int> find_min;
    int i = 1;
    while(i * i <= m ){
        int temp = DP(idx + 1, m - i * i);
        if(temp != -1)find_min.push_back(temp + (v[idx] - i) * (v[idx] - i));
        i++;
    }
    if(find_min.empty()) return -1;
    //printf("%d %d %d \n",idx , m, *min_element(find_min.begin(),find_min.end()));
    return *min_element(find_min.begin(),find_min.end());
}

int main()
{
    int m;
    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    memo.assign(n, vector<int>(m + 1, -2));

    cout << DP(0,m) << endl;
    return 0;
}*/
#include <stdio.h>

#define MAX_M 10000
#define MAX_N 10
#define INF 1000000000

int best[MAX_M+1][MAX_N+1];
int A[MAX_M+1];

int main(void)
{
	int M, N, i, j, k;
	scanf ("%d %d", &N, &M);
	for (i=1; i<=N; i++)
		scanf ("%d", &A[i]);

    best[0][0] = 0;
	for (i=1; i<=M; i++)
		best[i][0] = INF;

	for (j=1; j<=N; j++)
		for (i=0; i<=M; i++) {
			best[i][j] = INF;
			for (k=1; k*k<=i; k++)
				if ((A[j]-k)*(A[j]-k) + best[i-k*k][j-1] < best[i][j])
					best[i][j] = (A[j]-k)*(A[j]-k) + best[i-k*k][j-1];
		}

		if (best[M][N]==INF)
			printf ("-1\n");
		else
			printf ("%d\n", best[M][N]);

		return 0;
}
