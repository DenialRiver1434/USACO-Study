#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
using namespace std;
long N, M, a, b;
vector<long> starts, as, bs, finishes;
vector<tuple<long, long>> ranges;

int main() {
    cin >> N >> M;
    for (long i = 0; i < (M * 2 + 2); i ++){
        starts.push_back(0);
        finishes.push_back(0);
        as.push_back(0);
        bs.push_back(0);
    }
    for (long i = 0; i < N; i ++) {
        cin >> a >> b;
        as[a] ++; bs[b] ++;
    }
    for (long i = 0; i < (M * 2 + 2); i ++) {
        long st = 0, en = 0;
        for (long j = 0; j <= i; j ++){
            long k = i - j;
            st += as[j] * as[k]; en += bs[j] * bs[k];
        }
        starts[i] = st; finishes[i] = en;
    }
    long tc = 0;
    for (long i = 0; i < (M * 2 + 1); i ++){
        if(i > 0) tc += (starts[i] - finishes[i - 1]);
        else tc += starts[i];
        cout << tc << endl;
    }
}