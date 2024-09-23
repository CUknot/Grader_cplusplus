#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    typedef pair<double,pair<double,double>> prpw;
    double W;
    int N;
    cin >> W >> N;
    vector<double> p(N),w(N);
    vector<prpw> q(N);
    for(int i = 0; i < N; i++) cin >> p[i];
    for(int i = 0; i < N; i++) {
        cin >> w[i];
        q[i] = {p[i] / w[i], {p[i], w[i]}};
    }
    sort(q.begin(), q.end());

    double current_weight = 0;
    double current_price = 0;
    for(int i = N-1; i >= 0; i--) {
        double r = q[i].first;
        double price = q[i].second.first;
        double weight = q[i].second.second;

        if(current_weight +  weight < W){
            current_weight += weight;
            current_price += price;
        }
        else{
            current_price += r * (W - current_weight);
            break;
        }
    }
    printf("%.4f\n", current_price);
    return 0;
}
