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
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << endl; return out;};

ll T;

void tc () {
    ll N, M; cin >> N >> M;
    char grid[N][M];
    f0r (i, 0, N) {
        f0r (j, 0, M) {
            cin >> grid[i][j];
        }
    }

    f0r (t, 0, N) {
        f0r (i, 0, N - 1) {
            f0r (j, 0, M) {
                if (grid[i][j] == '*' && grid[i + 1][j] == '.') {
                    swap(grid[i][j], grid[i + 1][j]);
                }
            }
        }
    }

    f0r (i, 0, N) {
        f0r (j, 0, M) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main () {
    cin >> T;
    while (T --) {
        tc ();
        cout << endl;
    }
}