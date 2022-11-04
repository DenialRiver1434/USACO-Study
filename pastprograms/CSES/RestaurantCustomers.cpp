#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct change {
    int time;
    int change;
};

bool cmp (change a, change b) {
    return a.time < b.time;
}

int main(){
    int N;
    vector<change> times;
    cin >> N;
    for(int i = 0; i < N; i ++){
        int a, b;
        cin >> a >> b;
        change enter;
        change exit;
        enter.time = a;
        enter.change = 1;
        exit.time = b;
        exit.change = -1;
        times.push_back(enter);
        times.push_back(exit);
    }
    sort(times.begin(), times.end(), cmp);
    int best = 0;
    int size = 0;
    for(auto t : times) best = max(best, size += t.change);
    cout << best;
}