#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int evaluate (int N, vector<int> nums) {
    int c = 0;
    bitset<100000> valid;
    for (auto n : nums) valid[n] = 1;
    for (int i = 0; i < (N - 1); i ++) {
        if(valid[i]) c += 10;
        if(valid[i + 1]) c ++;
    }
    return c;
}

// Main

void solve () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int N, K, C1 = 0;
    cin >> N >> K;
    vector<int> ones;
    for (int i = 0; i < N; i ++) {
        char num; cin >> num;
        if (num == '1') {
            ones.pb(i);
            C1 ++;
        }
    }
    if(C1 == 0) {
        cout << 0 << endl;
        return;
    }

    // Move both to edge
    if(C1 > 1 && (ones[0] + (N - ones[C1 - 1] - 1)) <= K) {
        vector<int> temp; 
        for (auto o : ones) temp.pb(o);
        temp[0] = 0; temp[C1 - 1] = N - 1;
        cout << evaluate(N, temp) << endl;
        return;
    }

    if((N - ones[C1 - 1] - 1) <= K) {
        vector<int> temp; 
        for (auto o : ones) temp.pb(o);
        temp[C1 - 1] = N - 1;
        cout << evaluate(N, temp) << endl;
        return;
    }

    // Move all to left
    if((ones[0]) <= K) {
        vector<int> temp; 
        for (auto o : ones) temp.pb(o);
        temp[0] = 0;
        cout << evaluate(N, temp) << endl;
        return;
    }
    
    cout << evaluate(N, ones) << endl;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int T; cin >> T;
    while (T --) {
        solve();
    }
}