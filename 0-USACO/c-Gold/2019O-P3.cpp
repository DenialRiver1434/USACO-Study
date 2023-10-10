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
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1e5;
ll N, d = 0, best = 0;

ll c1 = 0, cost = 0;
stack<ll> l1, l0;
queue<ll> r1, r0;

int main () {
    fileread("balance");

    fin >> N;
    ll t1 = 0;
    f0r (i, 0, N) {
        bool x; fin >> x;
        c1 += x; t1 += x;
        if (x) l1.push(i);
        else l0.push(i);
        
        if (!x) d += t1;
    }
    t1 = 0;
    f0r (i, 0, N) {
        bool x; fin >> x;
        c1 += x; t1 += x;
        if (x) r1.push(i);
        else r0.push(i);

        if (!x) d -= t1;
    }

    if ((d >= 0 && c1 - N <= 0) || (d <= 0 && c1 - N >= 0)) {
        best = abs(d);
        while (1) {
            // Swap 1 0 to 0 1
            if (l1.empty()) break;
            if (r0.empty()) break;

            // Pushing 0 left through 1
            cost += r0.front();
            d += r0.front();

            cost += (N - l1.top());
            // Pushing 1 right through 0s
            d -= (N - l1.top() - 1);

            r0.pop(); l1.pop();
            d += c1 - N;
            best = min(best, abs(d) + cost);
        }
    }
    else {
        best = abs(d);
        while (1) {
            // Swap 0 1 to 1 0
            if (l0.empty()) break;
            if (r1.empty()) break;

            cost += r1.front();
            d -= r1.front();

            cost += (N - l0.top());
            d += (N - l0.top() - 1);

            r1.pop(); l0.pop();
            d -= c1 - N;
            best = min(best, abs(d) + cost);
        }
    }

    fout << best << endl;
}