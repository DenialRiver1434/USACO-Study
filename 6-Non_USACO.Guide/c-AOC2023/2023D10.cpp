// To adapt for own testcase you have to edit start value, and edit the S such that it fits in!

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
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

int main () {
    ifstream fin; fin.open("lineup.in");

    map<PL, V<PL>> conn, seccon;
    PL start = {128, 88};

    ll i = 0;
    V<string> grid;
    string num;
    while (fin >> num) {
        grid.pb(num);
        f0r (j, 0, len(num)) {
            if (num[j] == 'S') {
                start = {i, j};
            }
            else if (num[j] == '|') {
                conn[{i, j}].pb({i + 1, j});
                conn[{i, j}].pb({i - 1, j});
                seccon[{i + 1, j}].pb({i, j});
                seccon[{i - 1, j}].pb({i, j});
            }
            else if (num[j] == '-') {
                conn[{i, j}].pb({i, j - 1});
                conn[{i, j}].pb({i, j + 1});
                seccon[{i, j - 1}].pb({i, j});
                seccon[{i, j + 1}].pb({i, j});
            }
            else if (num[j] == 'L') {
                conn[{i, j}].pb({i - 1, j});
                conn[{i, j}].pb({i, j + 1});
                seccon[{i - 1, j}].pb({i, j});
                seccon[{i, j + 1}].pb({i, j});
            }
            else if (num[j] == 'J') {
                conn[{i, j}].pb({i - 1, j});
                conn[{i, j}].pb({i, j - 1});
                seccon[{i - 1, j}].pb({i, j});
                seccon[{i, j - 1}].pb({i, j});
            }
            else if (num[j] == 'F') {
                conn[{i, j}].pb({i + 1, j});
                conn[{i, j}].pb({i, j + 1});
                seccon[{i + 1, j}].pb({i, j});
                seccon[{i, j + 1}].pb({i, j});
            }
            else if (num[j] == '7') {
                conn[{i, j}].pb({i + 1, j});
                conn[{i, j}].pb({i, j - 1});
                seccon[{i + 1, j}].pb({i, j});
                seccon[{i, j - 1}].pb({i, j});
            }
        }
        i ++;
    }

    bool vis[1000][1000];
    memset(vis, 0, sizeof(vis));

    V<PL> search;
    PL ppos = {-1, -1}, cpos = start;
    while (true) {
        bool found = 0;
        for (PL c : conn[cpos]) {
            if (c == ppos) continue;
            else {
                ppos = cpos;
                cpos = c;
                found = 1;
                break;
            }
        }
        if (!found) {
            for (PL c : seccon[cpos]) {
                if (c == ppos) continue;
                else {
                    ppos = cpos;
                    cpos = c;
                    found = 1;
                    break;
                }
            }
        }
        vis[cpos.F][cpos.S] = 1;
        if (cpos == start) break;
    }

    ll tc = 0;
    f0r (i, 0, len(grid)) {
        f0r (j, 0, len(grid[0])) {
            if (vis[i][j]) continue;
            ll pass = 0;
            char pturn = ' ';
            f0r (k, j + 1, len(grid[0])) {
                if (vis[i][k]) {
                    if (grid[i][k] == '|') {
                        pass ++;
                    }
                    if (grid[i][k] == 'F') {
                        pturn = 'F';
                        pass ++;
                    }
                    if (grid[i][k] == 'L') {
                        pturn = 'L';
                        pass ++;
                    }
                    if (grid[i][k] == 'J' && pturn == 'L') {
                        pass ++;
                    }
                    if (grid[i][k] == '7' && pturn == 'F') {
                        pass ++;
                    }
                }
            }
            if (pass % 2 == 1) {
                tc ++;
            }
        }
    }
    cout << tc << endl;
}