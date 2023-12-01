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

const ll MAX_N = 1e5 + 5;

ll N, M, nums[MAX_N], maxadjust[MAX_N], minadjust[MAX_N];
ll maxr[MAX_N], maxl[MAX_N];

int main () {  
    cin >> N >> M;
    f0r (i, 0, N) {
        ll a; cin >> a;
        nums[i] = a;
        maxadjust[i] = a + i * M;
        minadjust[i] = a - i * M;
        maxl[i] = maxadjust[i];
        maxr[i] = minadjust[i];
    }

    f0r (i, 1, N) {
        maxl[i] = max(maxl[i], maxl[i - 1]);
    }
    For (i, N - 2, -1) {
        maxr[i] = max(maxr[i + 1], maxr[i]);
    }

    f0r (i, 0, N) {
        ll necadd1 = max(0LL, maxl[i] - maxadjust[i]);
        ll necadd2 = max(0LL, maxr[i] - minadjust[i]);
        nums[i] += max(necadd1, necadd2);
        cout << nums[i] << " ";
    }
}