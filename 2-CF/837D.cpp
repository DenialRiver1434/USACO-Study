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
#define For(i, end, begin) for (ll i = end - 1; i >= begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, K;
PL arr[200]; // 2, 5
ll possible[201][5200];
bool reach[201][5200];

int main () {
    cin >> N >> K;
    f0r (i, 0, N) {
        ll a; cin >> a;
        PL ans = {0, 0};
        while ((a % 5) == 0) {
            ans.S ++;
            a /= 5;
        }
        while ((a % 2) == 0) {
            ans.F ++;
            a /= 2;
        }
        arr[i] = ans;
    }

    reach[0][0] = 1;
    ll best = 0, max5 = 0;
    f0r (i, 0, N) {
        ll l2, l5; tie(l2, l5) = arr[i];
        For (j, K + 1, 1) {
            f0r (five, l5, 5200) {
                if(reach[j - 1][five - l5]) {
                    reach[j][five] = 1;
                    possible[j][five] = max(possible[j][five], possible[j - 1][five - l5] + l2);
                    best = max(best, min(five, possible[j][five]));
                }
            }
        }
        max5 += l5;
    }
    cout << best << endl;
}