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

ll cnt[11][1001][1001], N, M, K, pref[1001][1001];
V<ll> john, paul, matchpos;

int main () {
    fileread("team");

    fin >> N >> M >> K;
    cnt[0][0][0] = 1;
    ll lo = 0;
    f0r (i, 0, N) {
        ll a; fin >> a;
        john.pb(a);
        lo = min(a, lo);
    }
    f0r (i, 0, M) {
        ll a; fin >> a;
        paul.pb(a);
        lo = min(a, lo);
    }
    john.pb(lo - 1); paul.pb(lo - 2);
    sort(all(john)); sort(all(paul));
    
    f0r (i, 0, M + 1) {
        matchpos.pb(upper_bound(all(john), paul[i]) - john.begin());
    }

    f0r (i, 0, K) {
        f0r (j, 0, M + 1) {
            f0r (k, 0, N + 1) {
                pref[j][k] = 0;
            }
        }
        f0r (j, 0, M) {
            f0r (k, 0, N + 1) {
                ll nepos = max(matchpos[j + 1], k + 1);
                if(nepos < (N + 1)) {
                    pref[j + 1][nepos] += cnt[i][j][k];
                    pref[j + 1][nepos] %= MOD;
                }
            }
        }
        f0r (j, 1, M + 1) {
            f0r (k, 0, N + 1) {
                pref[j][k] += pref[j - 1][k];
                pref[j][k] %= MOD;
            }
        }
        f0r (j, 0, M + 1) {
            f0r (k, 1, N + 1) {
                pref[j][k] += pref[j][k - 1];
                pref[j][k] %= MOD;
            }
        }

        f0r (j, 0, M + 1) {
            f0r (k, 0, N + 1) {
                if (matchpos[j] <= k) {
                    cnt[i + 1][j][k] = pref[j][k];
                }
            }
        }
    }
    
    ll tot = 0;
    f0r (j, 0, M + 1) {
        f0r (k, 0, N + 1) {
            tot += cnt[K][j][k];
            tot %= MOD;
        }
    }
    fout << tot << endl;
}