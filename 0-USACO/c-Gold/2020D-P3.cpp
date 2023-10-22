#include "bits/stdc++.h"
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
vector<ll> decompx, decompy;
map<ll, ll> compressx, compressy;
vector<PL> inps;

int main () {
    cin >> N;
	f0r (i, 0, N) {
	    ll a, b;
		cin >> a >> b;
		decompx.pb(a); decompy.pb(b);
		inps.pb({a, b});
	}
	sort(all(decompx));
	sort(all(decompy));

    f0r (i, 0, N) {
        compressx[decompx[i]] = i;
        compressy[decompy[i]] = i;
    }

    ll tot = 0;
    f0r (row1, 0, N) {
        f0r (row2, row1 + 1, N) {
            ll rrow1 = decompx[row1], rrow2 = decompx[row2];
            ll leng = rrow2 - rrow1;

            set<ll> hori, combined;
            V<ll> left, right;
            for (auto pair : inps) {
                if (pair.F == rrow1) {
                    left.pb(pair.S);
                    combined.is(pair.S + 1);
                    combined.is(pair.S - leng);
                    hori.is(pair.S);
                }
                else if (pair.F > rrow1 && pair.F < rrow2) {
                    combined.is(pair.S + 1);
                    combined.is(pair.S - leng);
                    hori.is(pair.S);
                }
                else if (pair.F == rrow2) {
                    right.pb(pair.S);
                    combined.is(pair.S + 1);
                    combined.is(pair.S - leng);
                    hori.is(pair.S);
                }
            }
            sort(all(left));
            sort(all(right));

            for (ll col1 : combined) {
                ll col2 = col1 + leng;
                ll lcrit = lower_bound(all(left), col2 + 1) - lower_bound(all(left), col1);
                ll rcrit = lower_bound(all(right), col2 + 1) - lower_bound(all(right), col1);
                if (lcrit > 0 && rcrit > 0) {
                    tot ++;
                    if (hori.find(col2) != hori.end() && hori.find(col1) != hori.end()) {
                        tot --;
                    }
                }
            }
        }
    }
    
    f0r (col1, 0, N) {
        f0r (col2, col1 + 1, N) {
            ll rcol1 = decompy[col1], rcol2 = decompy[col2];
            ll leng = rcol2 - rcol1;

            set<ll> hori, combined;
            V<ll> left, right;
            for (auto pair : inps) {
                if (pair.S == rcol1) {
                    left.pb(pair.F);
                    combined.is(pair.F + 1);
                    combined.is(pair.F - leng);
                    hori.is(pair.F);
                }
                else if (pair.S > rcol1 && pair.S < rcol2) {
                    combined.is(pair.F + 1);
                    combined.is(pair.F - leng);
                    hori.is(pair.F);
                }
                else if (pair.S == rcol2) {
                    right.pb(pair.F);
                    combined.is(pair.F + 1);
                    combined.is(pair.F - leng);
                    hori.is(pair.F);
                }
            }
            sort(all(left));
            sort(all(right));

            for (ll row1 : combined) {
                ll row2 = row1 + leng;
                ll lcrit = lower_bound(all(left), row2 + 1) - lower_bound(all(left), row1);
                ll rcrit = lower_bound(all(right), row2 + 1) - lower_bound(all(right), row1);
                if (lcrit > 0 && rcrit > 0) {
                    tot ++;
                }
            }
        }
    }
    
    cout << tot + N + 1 << endl;
}