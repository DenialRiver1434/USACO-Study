#define pb push_back
#define mt make_tuple
#include <bits/stdc++.h>
using namespace std;

long long N, T;

long long getCompressedIndex(long long a, vector<long long> indices) {
	return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
}

int main () {
    cin >> T;
    for (long long i = 0; i < T; i ++) {
        cin >> N;
        long long a, b;
        vector<tuple<long long, long long>> coords, original;
        map<tuple<long long, long long>, long long> order, answer;

        for (long long i = 0; i < N; i ++) {
            cin >> a >> b;
            long long x = max(a, b), y = min(a, b);
            original.pb(mt(x, y));
            coords.pb(mt(x, y));
            coords.pb(mt(y, x));
            order[mt(x, y)] = i;
            order[mt(y, x)] = i;
        }
        sort(coords.begin(), coords.end());
        long long prevmin = 1000000000000, prevx = 0, curmin = 1000000000000, curx = 0;
        for (auto pair : coords) {
            long long x = get<0>(pair), y = get<1>(pair);
            if(x != curx) {
                if (curmin < prevmin) {
                    prevx = curx;
                    prevmin = curmin;
                }
                curmin = 1000000000000;
                curx = x;
            }
            if(y > prevmin) {
                answer[mt(x, y)] = order[mt(prevx, prevmin)];
            }
            else {
                answer[mt(x, y)] = -2;
                curmin = min(y, curmin);
            }
        }
        for (auto pair : original) {
            cout << answer[pair] + 1 << " ";
        }
        cout << endl;
    }
}