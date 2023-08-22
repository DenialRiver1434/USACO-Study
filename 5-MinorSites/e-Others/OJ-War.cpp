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
#define pq priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, a, b, c;

struct DSU {
	vector<PL> e;

	DSU(ll N) : e(N, {-1, 0}) {}

	PL get(ll x) { 
        if (e[x].F < 0) {
            return {x, 0};
        } 
        else {
            e[x].S += get(e[x].F).S; 
            e[x].F = get(e[x].F).F; 
            return e[x];
        }
    }

	bool connected(ll a, ll b) { 
        return get(a).F == get(b).F; 
    }

	bool unfriendly(ll a, ll b) { 
        return (get(a).S + get(b).S) % 2; 
    }

	int size(int x) { return -e[get(x).F].F; }

	void unite(ll x, ll y, bool enemies) {
        ll orgx = x, orgy = y;
        ll xdist, ydist;
		tie(x, xdist) = get(x); tie(y, ydist) = get(y);

		if ((x == y) && (unfriendly(orgx, orgy) != enemies)) { 
            cout << -1 << endl;
            return; 
        }
        if (x == y) {
            return;
        }

		if (e[x].F > e[y].F) { swap(x, y); }
		e[x].F += e[y].F;
        e[y].F = x;
        e[y].S = enemies;
	}
};

int main () {
    cin >> N;
    DSU dsu(N);
    while (1) {
        cin >> a >> b >> c;
        if (a == 0) break;
        else if (a == 1) {
            dsu.unite(b, c, 0);
        }
        else if (a == 2) {
            dsu.unite(b, c, 1);
        }
        else if (a == 3) {
            cout << (dsu.connected(b, c) && (!dsu.unfriendly(b, c))) << endl;
        }
        else {
            cout << (dsu.connected(b, c) && dsu.unfriendly(b, c)) << endl;
        }
    }
}