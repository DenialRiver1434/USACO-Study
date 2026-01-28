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
template<typename T> istream& operator>>(istream& in, pair<T, T>& a) {in >> a.F >> a.S; return in;};
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ' ' << a.S << '\n'; return out;};

typedef complex<ll> P;
#define x real()
#define y imag()

bool exists[5001][5001];
V<P> points;
ll R, C, N; 

int valid (P p) {
    if (p.x < 1 || p.x > R || p.y < 1 || p.y > C) return 0;
    return 1 + exists[p.x][p.y];
}

int main () {
    cin >> R >> C >> N;

    f0r (i, 0, N) {
        ll a, b; cin >> a >> b;
        exists[a][b] = 1;
        points.pb({a, b});
    }

    ll ans = 0;
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            if (i == j) continue;
            P I = points[i], J = points[j];
            P out = J + J - I;
            if (valid(out) == 0) {
                out = I + I - J;
                ll tc = 2;
                bool exit = true;
                while (valid(out) != 0) {
                    if (valid(out) == 1) {
                        exit = false;
                        break;
                    }
                    tc ++;

                    out += I;
                    out -= J;
                }
                if (exit && tc > 2) {
                    ans = max(ans, tc);
                }
            }
        }
    }

    cout << ans << endl;
}