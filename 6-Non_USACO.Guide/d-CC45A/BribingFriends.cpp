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

ll N, A, B, ans = 0;
ll dpmoney[2001], dpcones[2001]; // maximum popularity 

V<tuple<ll, ll, ll>> friends; // ice cream, popularity, cost

int main () {
	cin >> N >> A >> B;
    f0r (i, 0, N) {
        ll x, y, z; cin >> x >> y >> z;
        friends.pb({z, x, y});
    }
    sort(all(friends)); 

    for (auto f : friends) {
        ll ice, pop, cost;
        tie(ice, pop, cost) = f;

        // i = how much money remains
        // Spending own money (out of cones)
        f0r (i, 0, A - cost + 1) {
            dpmoney[i] = max(dpmoney[i], dpmoney[i + cost] + pop);
        }

        // Spending all cones, remaining money
        f0r (i, max(0LL, A - cost + 1), min(A, A - cost + B / ice) + 1) {
            ll req = (i - (A - cost)) * ice;
            dpmoney[i] = max(dpmoney[i], dpcones[req] + pop);
        }

        // i = how many cones remains
        // Spending only cones
        f0r (i, 0, B - ice * cost + 1) {
            dpcones[i] = max(dpcones[i], dpcones[i + ice * cost] + pop);
            dpmoney[A] = max(dpmoney[A], dpcones[i]);
        }
    }
    cout << dpmoney[0] << endl;
}