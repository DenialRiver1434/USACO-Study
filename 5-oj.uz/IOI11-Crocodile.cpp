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
#define For(i, end, begin) for (ll i = end - 1; i >= begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
 
int travel_plan(int N, int M, int edges[][2], int w[], int K, int P[]) {
    V<PL> conn[100000];
    PL safedist[100000];
 
    f0r (i, 0, M) {
        ll a = edges[i][0], b = edges[i][1], c = w[i];
        conn[a].pb({b, c});
        conn[b].pb({a, c});
    }
    f0r (i, 0, N) {
        safedist[i] = {INF, INF};
    }
 
    using T = pair<ll, ll>;
	priority_queue<T, vector<T>, greater<T>> pq;
 
    f0r (i, 0, K) {
        ll x = P[i];
        safedist[x] = {0, 0};
 
        for (auto p : conn[x]) {
            ll a, dist; tie(a, dist) = p;
            if ((safedist[a].F > dist) && (safedist[a].S > dist)) {
                if(safedist[a].S != safedist[a].F) {
                    pq.push({safedist[a].F, a});
                }
                safedist[a].S = safedist[a].F;
                safedist[a].F = dist;
            }
            else if (safedist[a].S > dist) {
                safedist[a].S = dist;
                pq.push({dist, a});
            }
        }
    }
 
    while (pq.size()) {
		ll cdist;
		ll node;
		tie(cdist, node) = pq.top();
		pq.pop();
		if (cdist != safedist[node].S) continue;
 
		for (auto p : conn[node]) {
            ll a, dist; tie(a, dist) = p;
            dist += cdist;
            if ((safedist[a].F > dist) && (safedist[a].S > dist)) {
                if(safedist[a].S != safedist[a].F) {
                    pq.push({safedist[a].F, a});
                }
                safedist[a].S = safedist[a].F;
                safedist[a].F = dist;
            }
            else if (safedist[a].S > dist) {
                safedist[a].S = dist;
                pq.push({dist, a});
            }
        }
	}
    return safedist[0].S;
}