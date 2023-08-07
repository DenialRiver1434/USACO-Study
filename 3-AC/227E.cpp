#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define pq priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

string s; ll K;
ll best[31][31][31][2000]; // cE, cK, cY
ll ck = 0, ce = 0, cy = 0, pre[31]; 
vector<ll> positions[3]; // 0 for E, 1 for K, 2 for Y

int main () {
    cin >> s >> K; K = min(K, len(s) * len(s));
    ll i = 0;
    for (auto ch : s) {
        if (ch == 'K') {
            ck ++;
            positions[1].pb(i ++);
        }
        else if (ch == 'E') {
            ce ++;
            positions[0].pb(i ++);
        }
        else {
            cy ++;
            positions[2].pb(i ++);
        }
    }
    
    
    ll cost[31][31][31][3];
    f0r (e, 0, ce + 1) {
        f0r (k, 0, ck + 1) {
            f0r (y, 0, cy + 1) {
                f0r (i, 0, len(s) + 1) pre[i] = 0;
                f0r (i, 0, e) pre[positions[0][i]] = 1;
                f0r (i, 0, k) pre[positions[1][i]] = 1;
                f0r (i, 0, y) pre[positions[2][i]] = 1;
                f0r (i, 1, len(s)) {
                    pre[i] += pre[i - 1];
                }

                ll pos = e + k + y - 1;
                if(e < ce) {
                    cost[e][k][y][0] = positions[0][e] - pre[positions[0][e]];
                }
                if(k < ck) {
                    cost[e][k][y][1] = positions[1][k] - pre[positions[1][k]];
                }
                if(y < cy) {
                    cost[e][k][y][2] = positions[2][y] - pre[positions[2][y]];
                }
            }
        }
    }

    best[0][0][0][0] = 1;
    f0r (bk, 0, K + 1) {
        f0r (e, 0, ce + 1) {
            f0r (k, 0, ck + 1) {
                f0r (y, 0, cy + 1) {
                    ll pos = e + k + y - 1;
                    // e was just added
                    if(e > 0) {
                        ll diff = cost[e - 1][k][y][0];
                        if(diff <= bk) {
                            best[e][k][y][bk] += best[e - 1][k][y][bk - diff];
                        }
                    }
                    if(k > 0) {
                        ll diff = cost[e][k - 1][y][1];
                        if(diff <= bk) {
                            best[e][k][y][bk] += best[e][k - 1][y][bk - diff];
                        }
                    }
                    if(y > 0) {
                        ll diff = cost[e][k][y - 1][2];
                        if(diff <= bk) {
                            best[e][k][y][bk] += best[e][k][y - 1][bk - diff];
                        }
                    }
                }
            }
        }
    }
    ll tot = 0;
    f0r (i, 0, K + 1) {
        tot += best[ce][ck][cy][i];
    }
    cout << tot << endl;
}