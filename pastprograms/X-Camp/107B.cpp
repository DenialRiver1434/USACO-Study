#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (int i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int T;

int main () {
    cin >> T;
    while (T --) {
        int N; cin >> N;
        vector<int> bits[31];
        for_loop (j, 0, N) {
            int a; cin >> a;
            for (int i = 29; i >= 0; i --) {
                int pi = pow(2, i);
                if(a >= pi) {
                    a -= pi;
                    bits[i].pb(j);
                }
            }
        }

        bool crit = false;
        vector<int> lefts[31], rights[31];

        for (int i = 0; i < 31; i ++) {
            vector<int> pos = bits[i];
            int ps = pos.size();
            if(ps == 0) {
                for_loop(j, 0, N) {
                    lefts[i].pb(0);
                    rights[i].pb(N - 1);
                }
            }
            else if(ps == 1) {
                cout << -1;
                crit = true;
                break;
            }
            else {
                int right = pos[ps - 1], left = pos[0];
                int bleft, bright;
                for_loop (j, 0, N) {
                    if(j <= left) {
                        bleft = N; bright = right - 1;
                    }
                    else if(j >= right) {
                        bleft = left + 1; bright = -1;
                    }
                    else {
                        bleft = 0; bright = N - 1;
                    }
                    rights[i].pb(bright);
                    lefts[i].pb(bleft);
                }
            }
        }
        if(crit) continue;

        int best = 0;
        for_loop (i, 0, N) {
            int left = 0, right = N;
            for_loop (j, 0, 31) {
                left = max(left, lefts[j][i]);
                right = min(right, rights[j][i]);
            }
            best = max(max(right - i + 1, i - left + 1), best);
        }
        if(!best) {
            cout << -1 << '\n';
        }
        else {
            cout << best << '\n';
        }
    }
}