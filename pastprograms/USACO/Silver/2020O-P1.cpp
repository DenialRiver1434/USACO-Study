#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll N, M, a, b;
vector<tuple<ll, ll>> intervals;

bool test (ll num) {
    ll prev = -1e18;
    ll count = 0;
    for (auto pair : intervals) {
        ll left = get<0>(pair), right = get<1>(pair), start = prev + num;
        if(start > right) continue;
        else {
            start = max(start, left);
            ll movement = (right - start) / num + 1;
            count += movement;
            prev = start + (movement - 1) * num;
        }
    }
    return (count >= N);
}

ll last_true(ll lo, ll hi) {
	lo--;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;
		if (test(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("socdist.in");
    fout.open("socdist.out");

    fin >> N >> M;
    for (long long i = 0; i < M; i ++){
        fin >> a >> b;
        intervals.pb(mt(a, b));
    }
    sort(intervals.begin(), intervals.end());
    fout << last_true(1, get<1>(intervals[M - 1])) << endl;
}