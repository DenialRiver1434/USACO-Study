// Prim's Algorithm O(N^2)

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

bool connected[7501];
ll dist[7501];
PQ<PL> pq;

ll get_cost (ll i, ll j) {
    if (i > j) swap(i, j);
    return (2019201913LL * (i + 1) + 2019201949LL * (j + 1)) % 2019201997LL;
}

int main () {
    fileread("walk");
    ll N, K; fin >> N >> K;

    f0r (i, 0, N) dist[i] = INF;

    V<ll> edges;
    ll curpos = 0;
    f0r (i, 0, N - 1) {
        connected[curpos] = 1;
        ll closest_dist = INF, closest_element = -1;
        f0r (j, 0, N) {
            if(connected[j]) continue;
            dist[j] = min(dist[j], get_cost(curpos, j));
            if (dist[j] < closest_dist) {
                closest_dist = dist[j];
                closest_element = j;
            }
        }
        curpos = closest_element;
        edges.pb(closest_dist);
    }
    sort(all(edges));
    fout << edges[N - K] << endl;
}