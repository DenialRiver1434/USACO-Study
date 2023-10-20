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

const ll MAX = 50;
PL appear[MAX][MAX]; // y, color
V<V<ll>> inps;

bool cross (PL a, PL b) {
    bool g1 = a.F > b.F;
    bool g2 = a.S > b.S;
    return g1 ^ g2;
}

void tc () {
    ll N, M; cin >> N >> M;
    f0r (i, 0, M) {
        f0r (j, 0, N) {
            appear[i][j] = {-1, -1};
        }
    }
    inps.clear();

    f0r (i, 0, M) {
        ll X; cin >> X;
        V<ll> line;
        f0r (j, 0, X) {
            ll col; cin >> col;
            col --;
            if (appear[i][col].F == -1) { appear[i][col].F = j; }
            else { appear[i][col].S = j; }
            line.pb(col);
        }
        inps.pb(line);
    }
    
    // Check whether we have any disjoint
    f0r (i, 0, N) {
        ll lappear = -1;
        f0r (j, 0, M) {
            if (appear[j][i].F == -1) continue;
            else if (lappear != -1 && lappear != j - 1) {
                cout << "NO" << endl;
                return ;
            }
            else {
                lappear = j;
            }
        }
    }
    
    // Check crossing self delta = 0
    V<ll> official(N, -1);
    f0r (i, 0, M) {
        V<ll> cur(N, -1);
        f0r (j, 0, N) {
            if (appear[i][j].F != -1) {
                cur[j] = INF;
            }
        }
        
        f0r (j, 0, N) {
            f0r (k, 0, N) {
                if (j == k) continue;
                
                ll x1, y1, x2, y2;
                tie (x1, y1) = appear[i][j];
                tie (x2, y2) = appear[i][k];
                if (x1 == -1 || x2 == -1) continue;
                
                if (x1 < x2 && x2 < y1 && y1 < y2) {
                    cout << "NO" << endl;
                    return;
                }

                if (x1 < x2 && x2 < y2 && y2 < y1) {
                    // Second (k) is fully inscribed in first (j)
                    cur[k] = j;
                }
            }
        }
        f0r (j, 0, N) {
            if (official[j] == -1) {
                official[j] = cur[j];
            }
            else if (cur[j] == -1) {
                continue;
            }
            else if (cur[j] != official[j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    
    // Check crossing other delta = 1
    f0r (i, 0, M - 1) {
        V<bool> req(N);
        f0r (j, 0, N) {
            if (appear[i][j].F != -1 && appear[i + 1][j].F != -1) req[j] = 1;
        }

        V<ll> l, r;
        for (auto a : inps[i]) {
            if (req[a]) l.pb(a);
        }
        for (auto a : inps[i + 1]) {
            if (req[a]) r.pb(a);
        }

        if (len(l) != len(r)) {
            cout << "NO" << endl;
            return;
        }
        f0r (i, 0, len(l)) {
            if (l[i] != r[i]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main () {
	ll T; cin >> T;
    while (T --) {
        tc ();
    }
}
