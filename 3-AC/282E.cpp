#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, M, arr[500];
vector<tuple<ll, ll, ll>> conn;

ll powermod(ll base, ll exp) {
	base %= M;
	ll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) // if n is odd
			result = result * base % M;
		base = base * base % M;
		exp /= 2; // divide by two
	}
	return result;
}

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int main() {
    cin >> N >> M;
    f0r (i, 0, N) {
        cin >> arr[i];
        f0r (j, 0, i) {
            conn.pb({(powermod(arr[i], arr[j]) + powermod(arr[j], arr[i])) % M, j, i});
        }
    }
    sort(all(conn), greater<tuple<ll, ll, ll>>());

    DSU dsu(N);
    ll miss = N - 1, tot = 0;
    for (auto c : conn) {
        ll weight, i, j; 
        tie(weight, i, j) = c;
        if (dsu.unite(i, j)) {
            miss --;
            tot += weight;
        }
        if (miss == 0) break;
    }
    cout << tot << endl;
}