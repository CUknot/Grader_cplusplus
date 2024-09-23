#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<double, int, double> myTuple; //current_sum,idx,current_weight
int N;
double W;

double maxratiosum(int idx, double w, vector<vector<double>> &v){
    double current_weight = 0;
    double max_sum = 0;
    for(int i = idx; i < N; i++) {
        if (current_weight + v[i][2] < w) {
            current_weight += v[i][2];
            max_sum += v[i][1];
        } else {
            max_sum += (w - current_weight) * v[i][0]; // Add fraction of the last item
            break;
        }
    }
    //printf("%d %f %f \n", idx, w, max_sum);
    return max_sum;
}

double bestfs(vector<vector<double>>& v, vector<double>& maxleftsum) {
    double Max_sum = -2e9;
    priority_queue<myTuple> q;
    q.push(myTuple(0, 0, 0));
    while(!q.empty()){
        double current_sum = get<0>(q.top());
        int idx = get<1>(q.top());
        double current_weight = get<2>(q.top());
        q.pop();

        Max_sum = max(Max_sum, current_sum);
        if(idx == N) continue;

        if(current_weight + v[idx][2] <= W && current_sum + v[idx][1] + maxleftsum[idx] > Max_sum){
            if(current_sum + v[idx][1] + maxratiosum(idx,W - current_weight,v) > Max_sum)
                q.push(myTuple(current_sum + v[idx][1], idx + 1, current_weight + v[idx][2]));
        }

        if(current_sum + maxleftsum[idx] > Max_sum)
            if(current_sum + maxratiosum(idx,W - current_weight,v) > Max_sum)
                q.push(myTuple(current_sum, idx + 1, current_weight));
    }
    return Max_sum;
}

int main()
{
    cin >> W >> N;
    vector<vector<double>> v(N, vector<double>(3)); // 2D vector to store ratio, prize, and weight
    vector<double> maxleftsum(N);
    double sum = 0, total = 0;
    for(int i = 0; i < N; i++) {
        cin >> v[i][1]; // prize
        sum += v[i][1];
    }
    for(int i = 0; i < N; i++) {
        cin >> v[i][2]; // weight
    }
    for(int i = 0; i < N; i++) {
        v[i][0] = v[i][1] / v[i][2]; // ratio
        total += v[i][1];
        maxleftsum[i] = sum - total;
    }
    sort(v.rbegin(), v.rend());
    printf("%.4f\n", bestfs(v,maxleftsum));
    return 0;
}

