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

// cnt is counting valid (x = k, y = k + diff) on [0, x]
ll cnt[40][2][2]; // carrying, isover

ll tc (ll x, ll diff) {
    if (x < 0) return 0;
    memset(cnt, 0, sizeof(cnt));

    V<ll> numx, numdiff;
    while (x > 0) {
        numx.pb(x % 3);
        x /= 3;
    }
    while (diff > 0) {
        numdiff.pb(diff % 3);
        diff /= 3;
    }
    ll N = max(len(numx), len(numdiff));
    if (N == 0) N ++;
    ll nx = len(numx), ny = len(numdiff);
    f0r (i, 0, N - nx) { numx.pb(0); }
    f0r (i, 0, N - ny) { numdiff.pb(0); }
    // reverse(all(numx)); reverse(all(numdiff));

    ll delta = numdiff[0];
    bool count[3][2];
    memset(count, 0, sizeof(count));
    if (delta == 0) {
        count[0][0] = true;
        count[1][0] = true;
        count[2][0] = true;
    }
    else if (delta == 1) {
        count[2][1] = true;
    }
    else if (delta == 2) {
        count[0][0] = true;
    }
    else {
        // Technically impossible here but for full-ness
        count[0][1] = true;
        count[1][1] = true;
        count[2][1] = true;
    }
    f0r (nd, 0, 3) {
        f0r (carry, 0, 2) {
            cnt[0][carry][nd > numx[0]] += count[nd][carry];
        }
    }

    f0r (i, 0, N - 1) {
        f0r (carry, 0, 2) {
            ll delta = carry + numdiff[i + 1];
            memset(count, 0, sizeof(count));

            if (delta == 0) {
                count[0][0] = true;
                count[1][0] = true;
                count[2][0] = true;
            }
            else if (delta == 1) {
                count[2][1] = true;
            }
            else if (delta == 2) {
                count[0][0] = true;
            }
            else {
                // Technically impossible here but for full-ness
                count[0][1] = true;
                count[1][1] = true;
                count[2][1] = true;
            }

            f0r (nd, 0, 3) {
                f0r (ncarry, 0, 2) {
                    if (!count[nd][ncarry]) continue;
                    if (nd > numx[i + 1]) {
                        cnt[i + 1][ncarry][1] += cnt[i][carry][0];
                        cnt[i + 1][ncarry][1] += cnt[i][carry][1];
                    }
                    else if (nd == numx[i + 1]) {
                        cnt[i + 1][ncarry][0] += cnt[i][carry][0];
                        cnt[i + 1][ncarry][1] += cnt[i][carry][1];
                    }
                    else {
                        cnt[i + 1][ncarry][0] += cnt[i][carry][0];
                        cnt[i + 1][ncarry][0] += cnt[i][carry][1];
                    }
                }
            }
        }
    }
    return cnt[N - 1][0][0];
}

int main () {    
    ll Q; cin >> Q;
    f0r (i, 0, Q) {
        ll x, y, c; cin >> c >> x >> y;
        if (y < x) swap(x, y);
        ll diff = y - x;
        cout << tc (x + c, diff) - tc (x - 1, diff) << endl;
    }
}