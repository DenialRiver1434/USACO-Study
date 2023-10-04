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

const ll MAX = 1000;
ll T, N, M, board[MAX][MAX], tot;
ll distup[MAX][MAX];
ll distleft[MAX][MAX];

stack<PL> dq[MAX];
ll s[MAX];

int main () {
    fastio;
    cin >> T;
    while (T --) {
        cin >> N >> M;
        f0r (i, 0, N) {
            f0r (j, 0, M) {
                cin >> board[i][j];
                distup[i][j] = distleft[i][j] = 0;
            }
        }
        f0r (j, 0, M) {
            while (!dq[j].empty()) {
                dq[j].pop();
            }
        }
        
        f0r (i, 0, N) {
            f0r (j, 0, M) {
                if (i == 0) distup[i][j] = 0;
                else if (board[i - 1][j] != board[i][j]) distup[i][j] = 0;
                else distup[i][j] = distup[i - 1][j] + 1;
            }
        }
        f0r (j, 0, M) {
            f0r (i, 0, N) {
                if (j == 0) distleft[i][j] = 1;
                else if (board[i][j - 1] != board[i][j]) distleft[i][j] = 1;
                else distleft[i][j] = distleft[i][j - 1] + 1;
            }
        }

        tot = 0;
        f0r (i, 0, N) {
            f0r (j, 0, M) {
                ll topx = distup[i][j];
                if (topx == 0) {
                    while (!dq[j].empty()) {
                        dq[j].pop();
                    }
                    s[j] = 0;
                }
                ll pre = i;
                while (!dq[j].empty()) {
                    if (dq[j].top().F >= distleft[i][j]) {
                        s[j] -= (dq[j].top().F - distleft[i][j]) * (pre - dq[j].top().S);
                        pre = dq[j].top().S;
                        dq[j].pop();
                    }
                    else break;
                }
                s[j] += distleft[i][j];
                dq[j].push({distleft[i][j], pre});
                tot += s[j];
            }
        }
        cout << tot << '\n';
    }
}
