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
 
V<V<ll>> conn;
V<ll> start, finish;
ll timer = 0;
void euler_tour (ll pos, ll pre) {
	start[pos] = timer ++;
	for (auto c : conn[pos]) {
		if (c != pre) {
			euler_tour(c, pos);
		}
	}
	finish[pos] = timer;
}
ll subsize (ll pos) {
    return finish[pos] - start[pos];
}

ll N, best = 0;
V<PL> fir, sec;
V<V<ll>> branch, missing;
V<ll> sums;

ll dfs1 (ll pos, ll pre) {
    V<ll> poss;
    ll totsize = 0;
	for (auto c : conn[pos]) {
		if (c != pre) {
            ll o = dfs1(c, pos);
            totsize += o;
            branch[pos].pb(o);
            poss.pb(o);
            sums[pos] += o;
		}
	}
    for (auto p : poss) {
        missing[pos].pb(totsize - p);
    }
    return totsize + subsize(pos);
}

void dfs2 (ll pos, ll pre, ll above) {
    above += (N - subsize(pos));
    sums[pos] += above;
    sums[pos] += N;
    best = max(best, sums[pos]);

    ll i = 0;
	for (auto c : conn[pos]) {
		if (c != pre) {
            dfs2(c, pos, above + missing[pos][i]);
            i ++;
		}
	}
}

int main () {
	cin >> N;
    conn = missing = branch = V<V<ll>>(N);
    start = finish = sums = V<ll>(N);
    fir = sec = V<PL>(N);

    f0r (i, 0, N - 1) {
        ll a, b; cin >> a >> b;
        conn[a - 1].pb(b - 1);
        conn[b - 1].pb(a - 1);
    }
    euler_tour(0, -1);

    dfs1 (0, -1);
    dfs2 (0, -1, 0);
    cout << best << endl;
}