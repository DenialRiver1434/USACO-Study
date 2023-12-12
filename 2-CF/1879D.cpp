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
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ", " << a.S << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, tuple<T, T, T>& a) {out << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 3e5 + 5;
bool nums[30][MAX_N];
ll tot = 0;

int main () {
    fastio;
    ll N; cin >> N;
    f0r (i, 0, N) {
        ll a; cin >> a;
        f0r (j, 0, 30) {
            nums[j][i] = a % 2;
            a /= 2;
        }
    }

    f0r (curbit, 0, 30) {
        ll tc = 0, oddpos = 0, oddtot = 0, evenpos = 1, eventot = 0, c1 = 0; // odd, even, odd, even

        f0r (i, 0, N) {
            eventot += evenpos; oddtot += oddpos;
            eventot %= MOD; oddtot %= MOD;
            c1 += nums[curbit][i];
            if (c1 % 2 == 0) {
                tc += oddtot;
                evenpos ++;
            }
            else {
                tc += eventot;
                oddpos ++;
            }
            tc %= MOD;
        }

        ll factor = (1 << curbit) % MOD;
        tot = (tot + factor * tc) % MOD;
    }

    cout << tot << '\n';
}