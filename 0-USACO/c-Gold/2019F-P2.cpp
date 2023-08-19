#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define ll long long
#define V vector
#define MS multiset
#define PL pair<int, int>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define For(i, end, begin) for (int i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000009
#define len(x) (int)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll sstart = 0, ssend = 0, limit = 0;
V<ll> stacks[100000];

ll binsearch (ll lo, ll hi, ll target) {
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (stacks[mid][0] > target) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
    return lo;
}

void evac (ll num) {
    ll viewer = sstart; 
    while (true) {
        bool found = 0;
        while (!stacks[viewer].empty()) {
            if (stacks[viewer][len(stacks[viewer]) - 1] < num) {
                sstart = viewer;
                limit = stacks[viewer][len(stacks[viewer]) - 1];
                stacks[viewer].pop_back();
            }
            else {
                found = 1;
                break;
            }
        }
        if (found) break;
        viewer ++;
    }
}

int main () {
    fileread("dishes");

    ll N; fin >> N;
    f0r (i, 0, N) {
        ll num; fin >> num;
        if (num < limit) {
            fout << i << endl;
            return 0;
        }

        ll pos = binsearch(sstart, ssend, num);
        if (pos == ssend) {
            stacks[ssend].pb(num);
            ssend ++;
            continue;
        }
        if (stacks[pos][len(stacks[pos]) - 1] < num) {
            evac (num);
        }
        stacks[pos].pb(num);
    }
    fout << N << endl;
}