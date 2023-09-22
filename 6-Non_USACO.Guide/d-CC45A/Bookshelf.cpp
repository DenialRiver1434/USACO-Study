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

const ll MAX_N = 1e5;
ll heights[MAX_N];
ll dp[MAX_N], distto[MAX_N], N, L;
V<PL> books;

ll pref (ll left, ll right) { // [left, right]
    if (left == 0) return distto[right];
    return distto[right] - distto[left - 1];
}

int main () {
	cin >> N >> L;
    f0r (i, 0, N) {
        ll a, b; cin >> a >> b;
        distto[i] = b;
        if (i > 0) distto[i] += distto[i - 1];
        books.pb({a, b});
        heights[i] = -1;
    }

    set<PL> sh;
    dp[0] = books[0].F;
    heights[0] = dp[0];
    sh.is({heights[0], 0});

    ll ppos = 0;
    deque<tuple<ll, ll, ll>> removed; // value, start, end
    removed.pb({books[0].F, 0, 1});
    f0r (i, 1, N) {
        ll height, width;
        tie(height, width) = books[i];

        if (removed.empty()) {
            removed.pb({height, i, i + 1});
            heights[i] = height + dp[i - 1];
            sh.is({height + dp[i - 1], i});
        }
        else {
            ll lhs = i;
            while (height >= get<0>(removed.back())) {
                lhs = get<1>(removed.back());
                sh.erase({heights[lhs], lhs});
                heights[lhs] = -1;
                removed.pop_back();
                if (removed.empty()) break;
            }
            removed.pb({height, lhs, i + 1});
            heights[lhs] = height;
            if (lhs > 0) heights[lhs] += dp[lhs - 1];
            sh.is({heights[lhs], lhs});
        }

        while (ppos < N) {
            if (pref(ppos, i) > L) {
                sh.erase({heights[ppos], ppos});
                heights[ppos] = -1;
                ppos ++;
                get<1>(removed.front()) = ppos;
                if (get<1>(removed.front()) == get<2>(removed.front())) removed.pop_front();
                heights[ppos] = dp[ppos - 1] + get<0>(removed.front());
                sh.is({heights[ppos], ppos});
            }
            else break;
        }
        dp[i] = (*sh.begin()).F;
    }
    cout << dp[N - 1] << endl;
}