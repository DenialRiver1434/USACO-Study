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

ll N;
V<PL> nums;

int main () {
    fileread("sort");

    fin >> N;
    bool found = 0;
    f0r (i, 0, N) {
        ll a; fin >> a;
        nums.pb({a, i});
        if (i > 0) {
            found |= nums[i].F < nums[i - 1].F;
        }
    }
    sort(all(nums));

    ll best = found;
    f0r (i, 0, N) {
        best = max(best, nums[i].S - i + 1);
    }
    fout << best << endl;
}