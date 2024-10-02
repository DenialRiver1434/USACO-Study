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
#define PQ priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

V<int> find_subset (int l, int u, V<int> wi) {
    V<pair<int, int>> w;
    f0r (i, 0, len(wi)) {
        w.pb({wi[i], i});
    }

    sort(all(w));
    
    int N = len(w);
    
    ll lower = 0, upper = 0;
    f0r (siz, 1, N + 1) {
        lower += w[siz - 1].F;
        upper += w[N - siz].F;
        
        if (upper < l) continue;
        if (lower > u) break;

        // Gradually add
        ll left = 0, right = siz, tot = lower;
        while (tot < l) {
            tot += w[right].F;
            tot -= w[left].F;
            left ++; right ++;
        }
        V<int> output;
        f0r (j, left, right) {
            output.pb(w[j].S);
        }
        return output;
    }
    return {};
}

// Remove int main () if submitting to oj.uz

int main () {
	int lower, upper, N;
    cin >> lower >> upper >> N;
    V<int> arr(N);
    cin >> arr;
    find_subset(lower, upper, arr);
}
