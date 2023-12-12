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

bool nums[100000][30];

void tc () {
    ll N, Q; 
    cin >> N >> Q;

    ll neccount[30] = {};

    f0r (i, 0, N) {
        ll a; cin >> a;
        f0r (j, 0, 30) {
            nums[i][j] = (a % 2);
            a /= 2;
            neccount[j] += nums[i][j];
        }
    }
    f0r (j, 0, 30) {
        if (neccount[j] % 2 == 1) {
            neccount[j] --;
        }
    }

    PL mans = {0, N};
    ll lhs = 0, rhs = 0, curcount[30] = {};
    while (lhs < N) {
        if (rhs < lhs) {
            rhs ++;
        }

        while (true) {
            bool good = 1;
            f0r (j, 0, 30) {
                if (curcount[j] < neccount[j]) {
                    good = 0;
                }
            }
            if (!good) {
                if (rhs == N) {
                    rhs ++;
                    break;
                }
                f0r (j, 0, 30) {
                    curcount[j] += nums[rhs][j];
                }
                rhs ++;
            }
            else {
                break;
            }
        }
        if (rhs > N) {
            break;
        }

        if (rhs - lhs < mans.S - mans.F) {
            mans = {lhs, rhs};
        }

        f0r (j, 0, 30) {
            curcount[j] -= nums[lhs][j];
        }
        lhs ++;
    }
    if (mans.S - mans.F == 0) {
        if (mans.F == 0) mans.S ++;
        else mans.F --;
    }
    cout << mans.F + 1 << " " << mans.S << endl;
    cin >> N >> Q;
}

int main () {
    ll T; cin >> T;
    while (T --) {
        tc ();
    }
}