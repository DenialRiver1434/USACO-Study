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

ll N, tot = 0;
V<tuple<ll, bool, ll, ll>> objects;

int main () {
	cin >> N;
    f0r (i, 0, N) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        objects.pb({c - b, a == 1, b + c, d});
    }
    sort(all(objects));

    map<ll, ll> papples;
    f0r (i, 0, N) {
        ll ypos = get<2>(objects[i]), cnt = get<3>(objects[i]);
        if (!get<1>(objects[i])) {
            papples[ypos] += cnt;
        }
        else {
            while (cnt > 0) {
                auto p = papples.lower_bound(ypos);
                if (p == papples.end()) break;
                ll x = (*p).F, c = (*p).S;
                tot += min(c, cnt);
                papples[x] -= min(c, cnt);
                cnt -= min(c, cnt);
                if (papples[x] != 0) break;
                else {
                    papples.erase(x);
                }
            }
        }
    }
    cout << tot << endl;
}