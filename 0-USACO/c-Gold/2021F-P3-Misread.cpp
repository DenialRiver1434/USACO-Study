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
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const V<PL> newdig = {{0, 0}, {0, 2}, {2, 0}, {2, 2}, {1, 1}};
const V<V<PL>> chng = {{{1, 1}, {0, 1}}, {{1, 1}, {0, 0}}, {{1, 1}}};
ll cnt[40][2][2];

ll tc (ll x, ll y) {
    if (x < 0 || y < 0) return 0;
    memset(cnt, 0, sizeof(cnt));

    V<ll> numx, numy;
    while (x > 0) {
        numx.pb(x % 3);
        x /= 3;
    }
    while (y > 0) {
        numy.pb(y % 3);
        y /= 3;
    }
    ll N = max(len(numx), len(numy));
    ll nx = len(numx), ny = len(numy);
    f0r (i, 0, N - nx) { numx.pb(0); }
    f0r (i, 0, N - ny) { numy.pb(0); }

    reverse(all(numx)); reverse(all(numy));

    // First digit
    for (auto n : newdig) {
        if (n.F > numx[0] || n.S > numy[0]) continue;
        cnt[0][n.F < numx[0]][n.S < numy[0]] ++;
    }

    f0r (i, 1, N) {
        for (auto n : newdig) {
            ll choice1, choice2;
            if (n.F > numx[i]) choice1 = 2;
            else if (n.F == numx[i]) choice1 = 1;
            else choice1 = 0;
            if (n.S > numy[i]) choice2 = 2;
            else if (n.S == numy[i]) choice2 = 1;
            else choice2 = 0;

            for (auto c1 : chng[choice1]) {
                for (auto c2 : chng[choice2]) {
                    cnt[i][c1.S][c2.S] += cnt[i - 1][c1.F][c2.F];
                }
            }
        }
    }

    return cnt[N - 1][0][0] + cnt[N - 1][0][1] + cnt[N - 1][1][0] + cnt[N - 1][1][1];
}

int main () {
    ll Q; cin >> Q;
    f0r (i, 0, Q) {
        ll a, b, c; cin >> c >> a >> b;
        cout << tc (a + c, b + c) - tc (a - 1, b + c) - tc (a + c, b - 1) + tc (a - 1, b - 1) << endl;
    }
}