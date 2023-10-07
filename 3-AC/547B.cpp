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
#define INF 1000000000000000000LL
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 2e5 + 2;

ll ans[MAX_N], N;

int main () {
    cin >> N;
    stack<PL> s;
    s.push({-1, -1});
    f0r (i, 0, N) {
        ll a; cin >> a;
        ans[N - 1] = min(ans[N - 1], a);

        ll early = i;
        while (s.top().F > a) {
            ans[i - s.top().S - 1] = max(ans[i - s.top().S - 1], s.top().F);
            early = s.top().S;
            s.pop();
        }
        if (s.top().F < a) {
            s.push({a, early});
        }
    }
    while (s.top().F > 0) {
        ans[N - s.top().S - 1] = max(ans[N - s.top().S - 1], s.top().F);
        s.pop();
    }

    For (i, N - 2, -1) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    f0r (i, 0, N) {
        cout << ans[i] << " ";
    }
}