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
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << endl; return out;};

int main () {
    ll N; cin >> N;
    V<ll> nums(N), ans(N, INF);
    cin >> nums;
    
    V<tuple<ll, ll, ll>> intervals;
    f0r (i, 0, N) {
        ans[i] = INF;
        f0r (j, i + 1, N + 1) {
            ll tot = 0;
            f0r (k, i, j) {
                tot += nums[k];
            }
            intervals.pb({tot, i, j});
        }
    }
    sort(all(intervals));

    ll li = len(intervals);
    f0r (i, 1, li) {
        ll tot1, tot2, i1, i2, j1, j2;
        tie(tot1, i1, j1) = intervals[i - 1];
        tie(tot2, i2, j2) = intervals[i];
        
        f0r (j, 0, N) {
            int s = 0;
            s += (i1 <= j && j < j1);
            s += (i2 <= j && j < j2);
            if (s == 1) {
                ans[j] = min(ans[j], tot2 - tot1);
            }
        }
    }
    cout << ans << endl;
}