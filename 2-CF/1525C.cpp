
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
#define inf 1000000000LL
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 3e5 + 5;
ll N, M, ans[MAX_N];
V<tuple<ll, bool, ll>> watched;

void solve () {
    V<tuple<ll, bool, ll>> lextra, rextra;
    for (auto w : watched) {
        if (get<1>(w)) {
            rextra.pb(w);
        }
        else {
            if (rextra.empty()) {
                lextra.pb(w);
            }
            else {
                auto lst = rextra.back();
                ans[get<2>(lst)] = (get<0>(w) - get<0>(lst)) / 2;
                ans[get<2>(w)] = (get<0>(w) - get<0>(lst)) / 2;
                rextra.pop_back();
            }
        }
    }

    f0r (i, 0, len(lextra) / 2) {
        ll pos1 = get<2>(lextra[2 * i]), pos2 = get<2>(lextra[2 * i + 1]);
        ll t = (get<0>(lextra[2 * i]) + get<0>(lextra[2 * i + 1])) / 2;
        ans[pos1] = t; ans[pos2] = t;
    }
    
    reverse(all(rextra));
    f0r (i, 0, len(rextra) / 2) {
        ll pos1 = get<2>(rextra[2 * i]), pos2 = get<2>(rextra[2 * i + 1]);
        ll t = (2 * M - get<0>(rextra[2 * i]) - get<0>(rextra[2 * i + 1])) / 2;
        ans[pos1] = t; ans[pos2] = t;
    }

    if ((len(rextra) % 2) && (len(lextra) % 2)) {
        auto lhs = lextra[len(lextra) - 1], rhs = rextra[len(rextra) - 1];
        ll t = M - (get<0>(rhs) - get<0>(lhs)) / 2;
        ans[get<2>(lhs)] = t;
        ans[get<2>(rhs)] = t;
    }
}

void tc () {
    cin >> N >> M;
    
    V<tuple<ll, bool, ll>> robots(N);
    f0r (i, 0, N) {
        cin >> get<0>(robots[i]);
        ans[i] = -1;
    }
    f0r (i, 0, N) {
        char x; cin >> x;
        get<1>(robots[i]) = (x == 'R');
        get<2>(robots[i]) = i;
    }
    sort(all(robots));

    for (auto r : robots) {
        if (get<0>(r) % 2 == 0) watched.pb(r);
    }
    solve ();
    watched.clear();
    for (auto r : robots) {
        if (get<0>(r) % 2 == 1) watched.pb(r);
    }
    solve ();
    watched.clear();

    f0r (i, 0, N) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main () {
    ll T; cin >> T;
    while (T --) {
        tc ();
    }
}
