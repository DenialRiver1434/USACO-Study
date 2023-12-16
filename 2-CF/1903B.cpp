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
 
ll T, N;
ll grid[1000][1000], valgrid[1000][1000];
ll arr[1000];
 
void tc () {
    cin >> N;
    f0r (i, 0, N) {
        ll val = -1;
        f0r (j, 0, N) {
            cin >> grid[i][j];
            if (i == j) continue;
            else if (val == -1) {
                val = grid[i][j];
            }
            else {
                val &= grid[i][j];
            }
        }
        if (val == -1) {
            arr[i] = 0;
        }
        else {
            arr[i] = val;
        }
    }
 
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            if (i == j) {
                valgrid[i][j] = 0;
            }
            else {
                valgrid[i][j] = (arr[i] | arr[j]);
            }
        }
    }
 
    bool good = 1;
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            if (grid[i][j] != valgrid[i][j]) good = 0;
        }
    }
    if (!good) {
        cout << "NO" << endl;
        return;
    }
    else {
        cout << "YES" << endl;
        f0r (i, 0, N) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
 
int main () {
    cin >> T;
    while (T --) {
        tc ();
    }
}
