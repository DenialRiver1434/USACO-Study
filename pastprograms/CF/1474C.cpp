#define pb push_back
#define mt make_tuple
#define is insert
#include <bits/stdc++.h>
using namespace std;

int T, N, a;
bool found;

void solve() {
    cin >> N;
    vector<int> inps;
    for (int i = 0; i < 2 * N; i ++) {
        cin >> a;
        inps.pb(a);
    }
    sort(inps.begin(), inps.end());
    multiset<int> nums;
    set<int> contents;
    for (int i = 0; i < 2 * N; i ++) {
        nums.insert(inps[i]);
        if(i != (2 * N - 1)) contents.insert(inps[i]);
    }

    bool done = false;
    for (auto c : contents) {
        multiset<int> tempnums;
        tempnums.insert(nums.begin(), nums.end());

        vector<tuple<int, int>> record;
        int prev = c + *tempnums.rbegin();
        found = true;
        for (int i = 0; i < N; i ++) {
            int top = *tempnums.rbegin();
            tempnums.erase(tempnums.find(top));
            if(tempnums.find(prev - top) == tempnums.end()) {
                found = false;
                break;
            }
            else {
                record.pb(mt(prev - top, top));
                tempnums.erase(tempnums.find(prev - top));
                prev = top;
            }
        }

        if(found) {
            cout << "YES" << endl;
            cout << c + *nums.rbegin() << endl;
            for (auto r : record) {
                cout << get<0>(r) << " " << get<1>(r) << endl;
            }
            done = true;
            break;
        }
    }
    if(!done) cout << "NO" << endl;
}

int main() {
    cin >> T;
    while (T --) {
        solve();
    }
}