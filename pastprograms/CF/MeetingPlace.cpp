#include <vector>
#include <iostream>
using namespace std;

int N, a;
vector<int> loc, vel;

double test(double n){
    double worst = 0;
    for(int i = 0; i < N; i ++) {
        double time = abs(loc[i] - n) / vel[i];
        if(time > worst) worst = time;
    }
    return worst;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i ++) {
        cin >> a;
        loc.push_back(a);
    }
    for(int i = 0; i < N; i ++) {
        cin >> a;
        vel.push_back(a);
    }
    double lb = 1, ub = 1000000000;
    for(int i = 0; i < 120; i ++) {
        double mid1 = (2 * lb + ub) / 3;
        double mid2 = (lb + 2 * ub) / 3;
        if(test(mid1) < test(mid2)) ub = mid2;
        else lb = mid1;
    }
    cout << test(lb);
}