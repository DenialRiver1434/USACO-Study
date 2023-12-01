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
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ", " << a.S << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, tuple<T, T, T>& a) {out << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << endl; return out;};

const ll MAX_N = 1005;
tuple<ll, ll, ll, ll> bounds[MAX_N * MAX_N];
bool illegal[MAX_N * MAX_N];
ll N, grid[MAX_N][MAX_N], pref[MAX_N][MAX_N];

int main () {  
    fileread("art");
    
    f0r (i, 0, MAX_N * MAX_N) {
        bounds[i] = {INF, INF, -INF, -INF};
    }

    fin >> N;
    bool fill = 0;
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            ll c; fin >> c; 
            grid[i][j] = c;
            if (c != 0) { fill = 1; }

            get<0>(bounds[c]) = min(get<0>(bounds[c]), i);
            get<2>(bounds[c]) = max(get<2>(bounds[c]), i + 1);
            get<1>(bounds[c]) = min(get<1>(bounds[c]), j);
            get<3>(bounds[c]) = max(get<3>(bounds[c]), j + 1);
        }
    }

    if (fill == 0) {
        fout << 0 << endl;
        return 0;
    }

    ll appear = 0;
    f0r (col, 1, N * N + 1) {
        if (get<0>(bounds[col]) == INF) {
            continue;
        }
        appear ++;
        pref[get<0>(bounds[col])][get<1>(bounds[col])] ++;
        pref[get<0>(bounds[col])][get<3>(bounds[col])] --;
        pref[get<2>(bounds[col])][get<1>(bounds[col])] --;
        pref[get<2>(bounds[col])][get<3>(bounds[col])] ++;
    }

    if (appear == 1) {
        fout << N * N - 1 << endl;
        return 0;
    }

    f0r (i, 0, N) {
        f0r (j, 0, N) {
            if (i > 0 && j > 0) {
                pref[i][j] -= pref[i - 1][j - 1];
            }
            if (i > 0) {
                pref[i][j] += pref[i - 1][j];
            }
            if (j > 0) {
                pref[i][j] += pref[i][j - 1];
            }

            if (pref[i][j] > 1) {
                illegal[grid[i][j]] = 1;
            }
            if (pref[i][j] > 0 && grid[i][j] == 0) {
                fout << 0 << endl;
                return 0;
            }
        }
    }
    
    ll miss = 0;
    f0r (i, 0, MAX_N * MAX_N) {
        if (illegal[i]) miss ++;
    }
    if (miss == appear) {
        fout << 0 << endl;
        return 0;
    }
    fout << N * N - miss << endl;
}