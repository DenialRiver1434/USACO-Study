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
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ", " << a.S << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, tuple<T, T, T>& a) {out << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 20;
const ll MAX_T = 12;
ll N, T;

ll affect[MAX_N][12];
bool reacht[1 << MAX_N][12];

ll tc () {
    string a, b; cin >> a >> b;
    ll lights = 0, switches = 0;
    f0r (i, 0, N) {
        if (a[i] == '1') {
            lights += 1 << (N - i - 1);
        }
    }
    f0r (i, 0, N) {
        if (b[i] == '1') {
            switches += 1 << (N - i - 1);
        }
    }

    f0r (t, 0, 12) {
        if (reacht[lights][t]) return t;
        lights ^= switches;
        if (switches % 2 == 0) {
            switches >>= 1;
        }
        else {
            switches >>= 1;
            switches += 1 << (N - 1);
        }
    }
    return 12;
}

int main () {
    cin >> T >> N;

    // Pre-pre-processing
    f0r (t, 1, 12) {
        f0r (j, 0, N) {
            ll tot = 0;
            f0r (k, j, j + t) {
                tot ^= 1 << (k % N);
            }
            affect[j][t] = tot;
        }
    }

    // Pre-processing
    reacht[0][0] = 1;
    f0r (t, 1, 12) {
        f0r (k, 0, 1 << N) {
            if (!reacht[k][t - 1]) continue;
            f0r (j, 0, N) {
                reacht[k ^ affect[j][t]][t] = 1;
            }
        }
    }
    
    while (T --) {
        cout << tc () << endl;
    }
}