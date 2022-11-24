#define pb push_back
#define mt make_tuple
#define is insert
#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector<tuple<int, int>> inputs;
vector<int> tbc;

int ans[200000];
set<int> starts[400001], finishes[400001];
set<int> avaliable;
int roomnum = 0;

int main() {
    cin >> N; 
    for (int i = 0; i < N; i ++) {
        cin >> a >> b;
        b ++;
        inputs.pb(mt(a, b));
        tbc.pb(a); tbc.pb(b);
    }
    sort(tbc.begin(), tbc.end());
    int end = 0;
    for (int i = 0; i < N; i ++) {
        auto p = inputs[i];
        int cstart = lower_bound(tbc.begin(), tbc.end(), get<0>(p)) - tbc.begin(), cend = lower_bound(tbc.begin(), tbc.end(), get<1>(p)) - tbc.begin();
        end = max(end, cend);
        starts[cstart].is(i); finishes[cend].is(i);
    }
    for (int i = 0; i <= end; i ++) {
        set<int> done = finishes[i];
        for (auto d : done) {
            avaliable.is(ans[d]);
        }
        set<int> start = starts[i];
        for (auto s : start) {
            if(avaliable.empty()) {
                ans[s] = ++ roomnum;
            }
            else {
                ans[s] = *avaliable.begin();
                avaliable.erase(ans[s]);
            }
        }
    }
    cout << roomnum << endl;
    for (int i = 0; i < N; i ++) {
        cout << ans[i] << " ";
    }
}