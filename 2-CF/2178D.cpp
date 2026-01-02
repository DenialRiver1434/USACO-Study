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
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void tc () {
    ll N, M; cin >> N >> M;
    if (2 * M > N) {
        f0r (i, 0, N) {
            ll a; cin >> a;
        }
        cout << -1 << endl;
        return;
    }
    if (M == 0) {
        V<PL> inps;
        f0r (i, 0, N) {
            ll a; cin >> a;
            inps.pb({a, i});
        }
        sort(all(inps));
        ll c = inps[N - 1].F, b = 0;
        For (i, N - 2, -1) {
            c -= inps[i].F;
            b ++;
            if (c <= 0) {
                break;
            }
        }

        if (c > 0) {
            cout << -1 << endl;
            return;
        } else {
            cout << N - 1 << endl;
            f0r (i, 0, N - b - 1) {
                cout << inps[i].S + 1 << " " << inps[i + b].S + 1 << endl;
            }
            f0r (i, N - b - 1, N - 1) {
                cout << inps[i].S + 1 << " " << inps[N - 1].S + 1 << endl;
            }
        }
    } else {
        cout << N - M << endl;
        V<PL> inps;
        f0r (i, 0, N) {
            ll a; cin >> a;
            inps.pb({a, i});
        }
        sort(all(inps));
        f0r (i, 0, N - M) {
            cout << inps[i + M].S + 1 << " " << inps[i].S + 1 << endl;
        }
    }
}

int main () {
    int T; cin >> T;
    while (T --) {
        tc ();
    }
}