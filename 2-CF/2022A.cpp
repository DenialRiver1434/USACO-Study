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

void tc () {
    ll N, R; cin >> N >> R;
    vector<ll> a(N);
    cin >> a;
    
    ll empty = 2 * R;
    ll odd = 0, even = 0;
    for (auto ch : a) {
        empty -= ch;
        if (ch % 2 == 1) {
            odd ++;
        } else {
            even ++;
        }
    }

    if (empty >= odd) {
        cout << (2 * R) - empty << endl;
        return;
    }
    odd -= empty;
    cout << (2 * R) - empty - odd << endl;
}

int main () {
	ll T; cin >> T;
	while (T --) {
		tc ();
	}
}
