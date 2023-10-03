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
#define INF 1000000000000000000LL
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX = 400;

V<PL> conn[MAX];
ll timer = 0, start[MAX], finish[MAX];

void euler_tour (ll pos, ll pre) {
	start[pos] = timer ++;
	for (auto c : conn[pos]) {
		if (c.F != pre) {
			euler_tour(c.F, pos);
		}
	}
	finish[pos] = timer;
}

PL dp[MAX][MAX + 1];
ll N, K, best = INF;

PL dfs (ll pos, ll pre, ll siz) {
    if (dp[pos][siz].F != INF + 1) return dp[pos][siz];
    dp[pos][siz].F = INF;
    if (finish[pos] - start[pos] == siz) {
        return dp[pos][siz] = {0, -1};
    }
    if (siz == 0) {
        return dp[pos][siz] = {1, -1};
    }
    
    V<PL> options;
    for (auto c : conn[pos]) {
        if (c.F != pre) {
            options.pb({finish[c.F] - start[c.F], c.F});
        }
    }
    sort(all(options));
    ll lo = len(options);
    
    ll bcount = INF, broute = -1;
    f0r (excl, 0, lo) {
        ll aK = siz - 1, tot = 0;
        f0r (j, 0, lo) {
            if (j == excl) continue;
            if (options[j].F > aK) {
                tot ++;
            }
            else {
                aK -= options[j].F;
            }
        }
        tot += dfs(options[excl].S, pos, aK).F;
        if (bcount > tot) {
            bcount = tot;
            broute = excl;
        }
    }
    return dp[pos][siz] = {bcount, broute};
}

bool searched[MAX][MAX + 1];

void dfs2 (ll pos, ll pre, ll siz) {
    if (searched[pos][siz]) return;
    searched[pos][siz] = 1;
    if (finish[pos] - start[pos] == siz) return;
    if (siz == 0) return;
    
    V<tuple<ll, ll, ll>> options;
    for (auto c : conn[pos]) {
        if (c.F != pre) {
            options.pb({finish[c.F] - start[c.F], c.F, c.S});
        }
    }
    sort(all(options));
    ll lo = len(options);
    
    ll aK = siz - 1, tot = 0, excl = dp[pos][siz].S, spec;
    f0r (j, 0, lo) {
        if (j == excl) {
            spec = get<2>(options[j]);
            continue;
        }
        if (get<0>(options[j]) > aK) {
            cout << get<2>(options[j]) + 1 << endl;
        }
        else {
            aK -= get<0>(options[j]);
        }
    }
    if (aK == 0) {
        cout << spec + 1 << endl;
    }
    else {
        dfs2(get<1>(options[excl]), pos, aK);
    }
}

int main () {
    cin >> N >> K;

    f0r (i, 0, N - 1) {
        ll a, b; cin >> a >> b;
        conn[a - 1].pb({b - 1, i});
        conn[b - 1].pb({a - 1, i});
    }
    
    ll bstartcost = INF, bstart = -1;
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            f0r (k, 0, K + 1) {
                dp[j][k] = {INF + 1, 0};
                searched[j][k] = 0;
            }
            start[j] = finish[j] = 0;
        }
        timer = 0;
        euler_tour(i, -1);
        ll opt = dfs(i, -1, K).F;
        if (opt < bstartcost) {
            bstartcost = opt;
            bstart = i;
        }
    }

    cout << bstartcost << endl;
    f0r (j, 0, N) {
        f0r (k, 0, K + 1) {
            dp[j][k] = {INF + 1, 0};
            searched[j][k] = 0;
        }
        start[j] = finish[j] = 0;
    }
    timer = 0;
    euler_tour(bstart, -1);
    dfs(bstart, -1, K);
    dfs2 (bstart, -1, K);
}