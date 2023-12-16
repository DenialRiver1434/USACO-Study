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

const ll MAX_N = 5001;

ll N;
string s;
bool ispal[MAX_N][MAX_N];
ll palval[MAX_N][MAX_N];
ll val[MAX_N];

int main () {
    memset(palval, -1, sizeof(palval));
    cin >> s;
    N = len(s);

    ispal[N][N] = 1;
    f0r (i, 0, N) {
        ispal[i][i + 1] = 1;
        ispal[i][i] = 1;
        palval[i][i + 1] = 0;
        val[0] ++;
    }

    f0r (diff, 2, N + 1) {
        f0r (i, 0, N + 1 - diff) {
            ll rhs = i + diff;
            ispal[i][rhs] = (ispal[i + 1][rhs - 1]) && (s[i] == s[rhs - 1]);

            if (!ispal[i][rhs]) { continue; }
            ll mid1 = i + (rhs - i) / 2, mid2 = rhs - (rhs - i) / 2;
            if (ispal[i][mid1] && ispal[mid2][rhs]) {
                palval[i][rhs] = palval[i][mid1] + 1; // Possible issue?
                val[palval[i][rhs]] ++;
            }
            else {
                palval[i][rhs] = 0;
                val[0] ++;
            }
        }
    }

    For (i, N - 2, -1) {
        val[i] += val[i + 1];
    }
    f0r (i, 0, N) {
        cout << val[i] << " ";
    }
}