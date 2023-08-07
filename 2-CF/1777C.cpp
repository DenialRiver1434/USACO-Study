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
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

map<ll, ll> cnt;
vector<ll> a; 
ll N, M;

void add (int n) {
    set<int> ret;
	for (int i = 1; (i * i <= n) && (i <= M); i++) {
		if (n % i == 0) {
            ret.is(i);
            if((n / i) <= M) ret.is(n / i);
		}
	}
    for (auto r : ret) {
        if(cnt.find(r) == cnt.end()) {
            cnt[r] = 1;
        }
        else cnt[r] ++;
    }
}

void unadd (int n) {
    set<int> ret;
	for (int i = 1; (i * i <= n) && (i <= M); i++) {
		if (n % i == 0) {
            ret.is(i);
            if((n / i) <= M) ret.is(n / i);
		}
	}
    for (auto r : ret) {
        if(cnt[r] == 1) {
            cnt.erase(cnt.find(r));
        }
        else cnt[r] --;
    }
}

int main () {
    fastio;
    ll T; cin >> T;
    while (T --) {
        cin >> N >> M;
        cnt.clear();
        a.clear();

        set<ll> nums;
        f0r (i, 0, N) {
            ll x; cin >> x;
            nums.is(x);
        }
        for (auto n : nums) {
            a.pb(n);
        }
        N = len(a);

        ll left = 0, right = 0, best = INF;
        while ((right <= N) && (left <= N)) {
            while ((right < N) && (len(cnt) < M)) {
                add (a[right ++]);
            }
            if(len(cnt) == M) {
                best = min(best, a[right - 1] - a[left]);
            }
            unadd(a[left ++]);
        }
        if(best == INF) {
            cout << -1 << endl;
        }
        else cout << best << endl;
    }
}