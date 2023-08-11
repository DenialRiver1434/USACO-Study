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

ll N, lT, nums[100000];
V<PL> ranges[100000];

void tc () {
    cin >> N;
    V<PL> temp;
    f0r (i, 0, N) {
        cin >> nums[i];
        temp.pb({nums[i], 1});
        ranges[i].clear();
    }
    
    lT = len(temp);
    PL pending = (temp[0]);
    f0r (i, 1, lT) {
        if(pending.F == temp[i].F) {
            pending.S += temp[i].S;
        }
        else {
            ranges[0].pb(pending);
            pending = temp[i];
        }
    }
    ranges[0].pb(pending);

    f0r (i, 1, N) {
        temp.clear();
        lT = len(ranges[i - 1]);
        f0r (j, 0, lT) {
            if (j > 0) {
                temp.pb({gcd(ranges[i - 1][j - 1].F, ranges[i - 1][j].F), 1});
            }
            if (ranges[i - 1][j].S > 1) temp.pb({ranges[i - 1][j].F, ranges[i - 1][j].S - 1});
        }
        lT = len(temp);
        PL pending = (temp[0]);
        f0r (j, 1, lT) {
            if(pending.F == temp[j].F) {
                pending.S += temp[j].S;
            }
            else {
                ranges[i].pb(pending);
                pending = temp[j];
            }
        }
        ranges[i].pb(pending);
    }

    f0r (i, 0, N) {
        ll best = 0;
        for (auto r : ranges[i]) {
            best = max(best, r.F);
        }
        cout << best << " ";
    }
    cout << endl;
}

int main () {
    int T; cin >> T;
    while (T --) { tc(); }
}