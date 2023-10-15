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

const ll MAX_N = 1e5;
ll N, msize = 0, lappear[MAX_N + 1];
bool active[MAX_N], done[MAX_N];
V<ll> arr;

int main () {
    fileread("art2");

    fin >> N;
    f0r (i, 0, N) {
        ll a; fin >> a;
        arr.pb(a);
        lappear[a] = i;
    }
    lappear[0] = -1;

    stack<ll> pstack;
    pstack.push(0);
    active[0] = 1;
    f0r (i, 0, N) {
        ll a = arr[i];
        
        if (done[a]) {
            fout << -1 << endl;
            return 0;
        }

        if (!active[a]) {
            pstack.push(a);
            active[a] = 1;
        }
        else {
            while (pstack.top() != a) {
                done[pstack.top()] = 1;
                active[pstack.top()] = 0;
                pstack.pop();
            }
        }

        msize = max(msize, len(pstack) - 1);

        if (i == lappear[a]) {
            pstack.pop();
            done[a] = 1;
            active[a] = 0;
        }
    }
    fout << msize << endl;
}