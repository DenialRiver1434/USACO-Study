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

const ll MAX_N = 1e5 + 5;
ll dpu1[MAX_N], dpe[MAX_N], dpd1[MAX_N]; // Right-most end

int main () {
	fastio;

    ll T; cin >> T;
    while (T --) {
		ll N; cin >> N;
		string grid[2]; 
		cin >> grid[0] >> grid[1];

		f0r (i, 0, N + 5) {
			dpu1[i] = dpe[i] = dpd1[i] = -INF;
		}
		dpe[0] = 0;
		f0r (i, 0, N) {
			int bonus = 0;
			int co = 0;

			// dpe[i] -> dpu1[i + 2]
			bonus = 0;
			co = 0;
			co += (grid[0][i + 1] == 'A');
			co += (grid[0][i] == 'A');
			co += (grid[1][i] == 'A');
			bonus += (co >= 2);
			dpu1[i + 2] = max(dpu1[i + 2], dpe[i] + bonus);

			// dpe[i] -> dpd1[i + 2]
			bonus = 0;
			co = 0;
			co += (grid[1][i + 1] == 'A');
			co += (grid[0][i] == 'A');
			co += (grid[1][i] == 'A');
			bonus += (co >= 2);
			dpd1[i + 2] = max(dpd1[i + 2], dpe[i] + bonus);

			// dpe[i] -> dpe[i + 3]
			bonus = 0;
			co = 0;
			co += (grid[0][i] == 'A');
			co += (grid[0][i + 1] == 'A');
			co += (grid[0][i + 2] == 'A');
			bonus += (co >= 2);
			co = 0;
			co += (grid[1][i] == 'A');
			co += (grid[1][i + 1] == 'A');
			co += (grid[1][i + 2] == 'A');
			bonus += (co >= 2);
			dpe[i + 3] = max(dpe[i + 3], dpe[i] + bonus);

			// dpu1[i]
			if (i > 0) {
				// dpu1[i] -> dpe[i + 1]
				bonus = 0;
				co = 0;
				co += (grid[1][i] == 'A');
				co += (grid[0][i] == 'A');
				co += (grid[1][i - 1] == 'A');
				bonus += (co >= 2);
				dpe[i + 1] = max(dpe[i + 1], dpu1[i] + bonus);

				// dpu1[i] -> dpu1[i + 3]
				bonus = 0;
				co = 0;
				co += (grid[0][i] == 'A');
				co += (grid[0][i + 1] == 'A');
				co += (grid[0][i + 2] == 'A');
				bonus += (co >= 2);
				co = 0;
				co += (grid[1][i - 1] == 'A');
				co += (grid[1][i] == 'A');
				co += (grid[1][i + 1] == 'A');
				bonus += (co >= 2);
				dpu1[i + 3] = max(dpu1[i + 3], dpu1[i] + bonus);
			}
			
			// dpd1[i]
			if (i > 0) {
				// dpd1[i] -> dpe[i + 1]
				bonus = 0;
				co = 0;
				co += (grid[0][i] == 'A');
				co += (grid[1][i] == 'A');
				co += (grid[0][i - 1] == 'A');
				bonus += (co >= 2);
				dpe[i + 1] = max(dpe[i + 1], dpd1[i] + bonus);

				// dpd1[i] -> dpd1[i + 3]
				bonus = 0;
				co = 0;
				co += (grid[1][i] == 'A');
				co += (grid[1][i + 1] == 'A');
				co += (grid[1][i + 2] == 'A');
				bonus += (co >= 2);
				co = 0;
				co += (grid[0][i - 1] == 'A');
				co += (grid[0][i] == 'A');
				co += (grid[0][i + 1] == 'A');
				bonus += (co >= 2);
				dpd1[i + 3] = max(dpd1[i + 3], dpd1[i] + bonus);
			}
		}
		cout << dpe[N] << '\n';
    }
}
