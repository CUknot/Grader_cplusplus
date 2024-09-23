#include <iostream>

using namespace std;

typedef long long ll;

int findQuadrant(ll size, ll x, ll y){
    int out = 0;
    if (x >= size/2) out += 1;
    if (y >= size/2) out += 2;
    return out;
}

ll dc(ll size, ll x, ll y, int type, int* arr){
    ll out;
    if(type % 2) swap(x,y);
    //cout << size << x << y << "\n";
    if (size > 2){
        int q = findQuadrant(size, x, y);
        //cout << q << "\n";
        out = dc(size/2,x % (size/2),y % (size/2),q,arr);
    }
    else{
        out = arr[x + 2 * y];
    }
    if(type / 2) return -out;
    else return out;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    int arr[4];
    cin >> n >> m;
    for(int i = 0; i < 4; i++) cin >> arr[i];
    ll size = 1LL << n;

    for(int i = 0; i < m; i++) {
        ll x,y;
        cin >> y >> x;
        cout << dc(size,x - 1,y - 1,0,arr) << "\n";
    }
    return 0;
}
