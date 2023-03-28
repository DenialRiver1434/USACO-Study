#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define vi vector<ll>
#define vpi vector<pair<ll, ll>>
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

ll A, B, N, M, tot = 0;
vi xs = {0}, ys = {0};
vector<tuple<ll, ll, bool>> dists;
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("fencedin.in"); fout.open("fencedin.out");

	fin >> A >> B >> N >> M;
	xs.pb(A);
	ys.pb(B);
	f0r (i, 0, N) {
		ll a; fin >> a;
		xs.pb(a);
	}
	sort(xs.begin(), xs.end());
	f0r (i, 0, M) {
		ll a; fin >> a;
		ys.pb(a);
	}
	sort(ys.begin(), ys.end());
	f0r (i, 0, N + 1) {
		dists.pb(mt(xs[i + 1] - xs[i], i, 0));
	}
	f0r (i, 0, M + 1) {
		dists.pb(mt(ys[i + 1] - ys[i], i, 1));
	}
	sort(dists.begin(), dists.end());

	ll countx = 0, county = 0;
	for (auto d : dists) {
		ll dist, pos; bool typ;
		tie(dist, pos, typ) = d;
		if(typ) {
			if(countx == 0) {
				tot += N * dist;
			}
			else tot += min(N, N - county + 1) * dist;
			countx ++;
		}
		else {
			if(county == 0) {
				tot += M * dist;
			}
			else tot += min(M, M - countx + 1) * dist;
			county ++;
		}
	}
	fout << tot << endl;
}