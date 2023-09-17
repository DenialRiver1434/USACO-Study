#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, finish) for (ll i = begin; i < finish; i ++) 
#define For(i, finish, begin) for (ll i = finish; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, N1, N2, pow3[26];
map<PL, PL> assignment;
V<tuple<ll, ll, ll>> attitudes;

void ans (ll a, ll b) {
	f0r (j, 0, N1) {
		if (a % 3 == 0) {
			cout << "MW" << endl;
		}
		else if  (a % 3 == 1) {
			cout << "LW" << endl;
		}
		else {
			cout << "LM" << endl;
		}
		a /= 3;
	}
	f0r (j, 0, N2) {
		if (b % 3 == 0) {
			cout << "MW" << endl;
		}
		else if  (b % 3 == 1) {
			cout << "LW" << endl;
		}
		else {
			cout << "LM" << endl;
		}
		b /= 3;
	}
}

int main () {
	pow3[0] = 1;
	f0r (i, 1, 26) pow3[i] = 3LL * pow3[i - 1];

	cin >> N;
	f0r (i, 0, N) {
		ll a, b, c; cin >> a >> b >> c;
		attitudes.pb({a, b, c});
	}

	N1 = N / 2;
	f0r (i, 0, pow3[N1]) {
		ll ci = i;
		ll cntl = 0, cntm = 0, cntw = 0;
		f0r (j, 0, N1) {
			if (ci % 3 == 0) {
				cntm += get<1>(attitudes[j]);
				cntw += get<2>(attitudes[j]);
			}
			else if  (ci % 3 == 1) {
				cntl += get<0>(attitudes[j]);
				cntw += get<2>(attitudes[j]);
			}
			else {
				cntl += get<0>(attitudes[j]);
				cntm += get<1>(attitudes[j]);
			}
			ci /= 3;
		}
		if (assignment.find(make_pair(cntl - cntm, cntm - cntw)) == assignment.end()) {
			assignment[make_pair(cntl - cntm, cntm - cntw)] = {i, cntl};
		}
		else if (assignment[{cntl - cntm, cntm - cntw}].S < cntl) {
			assignment[{cntl - cntm, cntm - cntw}] = {i, cntl};
		}
	}

	ll bestx = -INF;
	PL best = {INF, INF};
	N2 = N1 + N % 2;
	f0r (i, 0, pow3[N2]) {
		ll ci = i;
		ll cntl = 0, cntm = 0, cntw = 0;
		f0r (j, 0, N2) {
			if (ci % 3 == 0) {
				cntm += get<1>(attitudes[j + N1]);
				cntw += get<2>(attitudes[j + N1]);
			}
			else if  (ci % 3 == 1) {
				cntl += get<0>(attitudes[j + N1]);
				cntw += get<2>(attitudes[j + N1]);
			}
			else {
				cntl += get<0>(attitudes[j + N1]);
				cntm += get<1>(attitudes[j + N1]);
			}
			ci /= 3;
		}
		if (assignment.find({cntm - cntl, cntw - cntm}) != assignment.end()) {
			if (assignment[{cntm - cntl, cntw - cntm}].S + cntl > bestx) {
				bestx = assignment[{cntm - cntl, cntw - cntm}].S + cntl;
				best.F = assignment[{cntm - cntl, cntw - cntm}].F;
				best.S = i;
			}
		}
	}
	if (bestx == -INF) cout << "Impossible" << endl;
	else ans(best.F, best.S);
}