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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

V<ll> start, finish, conn[200000], euler;
ll timer = 0;
void euler_tour (ll pos, ll pre) {
	start[pos] = timer ++;
    euler.pb(pos);
	for (auto c : conn[pos]) {
		if (c != pre) {
			euler_tour(c, pos);
		}
	}
	finish[pos] = timer;
}

int main() {
    fileread("promote");
    ll N; fin >> N; 
    start = finish = V<ll>(N);
    V<ll> val(N); fin >> val;
    f0r (i, 1, N) {
        ll a; fin >> a;
        conn[a - 1].pb(i);
        conn[i].pb(a - 1);
    }
    euler_tour (0, -1);
	
	Tree<ll> tall, allbelow, allabove;
	for (auto v : val) tall.is(-v);
    V<ll> ans;

    V<tuple<ll, ll, ll>> qbelow, qabove;
    f0r (i, 0, N) {
        ans.pb(tall.order_of_key(-val[i]));
        qbelow.pb({start[i], val[i], i});
        qabove.pb({-finish[i], val[i], i});
    }
    sort(all(qbelow)); sort(all(qabove));

    ll prepos = 0;
    for (auto q : qbelow) {
        ll pos, num, ei;
        tie(pos, num, ei) = q;
        f0r (i, prepos, pos) {
            allbelow.is(-val[euler[i]]);
        }
        ans[ei] -= allbelow.order_of_key(-num);
        prepos = pos;
    }
    prepos = N - 1;
    for (auto q : qabove) {
        ll pos, num, ei;
        tie(pos, num, ei) = q;
        pos = -pos;
        For (i, prepos, pos - 1) {
            allabove.is(-val[euler[i]]);
        }
        ans[ei] -= allabove.order_of_key(-num);
        prepos = pos - 1;
    }
    for (auto a : ans) {
        fout << a << endl;
    }
}
