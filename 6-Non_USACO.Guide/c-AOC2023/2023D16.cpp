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


ll N = 0, M;
char grid[200][200];
bool passed[200][200][4]; // 0 right 1 down 2 left 3 up

void buscar (ll x, ll y, ll dir) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (passed[x][y][dir]) return;
    passed[x][y][dir] = 1;

    if (grid[x][y] == '.') {
        if (dir == 0) {
            y ++;
        }
        else if (dir == 1) {
            x ++;
        }
        else if (dir == 2) {
            y --;
        }
        else {
            x --;
        }
        buscar (x, y, dir);
    }
    else if (grid[x][y] == '|') {
        if (dir == 0 || dir == 2) {
            buscar(x - 1, y, 3);
            buscar(x + 1, y, 1);
        }
        else if (dir == 1) {
            buscar (x + 1, y, 1);
        }
        else {
            buscar (x - 1, y, 3);
        }
    }
    else if (grid[x][y] == '-') {
        if (dir == 1 || dir == 3) {
            buscar(x, y - 1, 2);
            buscar(x, y + 1, 0);
        }
        else if (dir == 0) {
            buscar (x, y + 1, 0);
        }
        else {
            buscar(x, y - 1, 2);
        }
    }
    else if (grid[x][y] == '\\') {
        if (dir == 0) {
            buscar(x + 1, y, 1);
        }
        else if (dir == 1) {
            buscar(x, y + 1, 0);
        }
        else if (dir == 2) {
            buscar(x - 1, y, 3);
        }
        else {
            buscar(x, y - 1, 2);
        }
    }
    else {
        if (dir == 0) {
            buscar(x - 1, y, 3);
        }
        else if (dir == 1) {
            buscar(x, y - 1, 2);
        }
        else if (dir == 2) {
            buscar(x + 1, y, 1);
        }
        else {
            buscar(x, y + 1, 0);
        }
    }
}

int main () {
    ifstream fin; fin.open("lineup.in");
    string num;
    while (fin >> num) {
        M = len(num);
        f0r (i, 0, len(num)) {
            grid[N][i] = num[i];
        }
        N ++;
    }

    ll best = 0;

    f0r (i, 0, N) { // Right
        buscar(i, 0, 0);
        ll tc = 0;
        f0r (i, 0, N) {
            f0r (j, 0, N) {
                if (passed[i][j][0] || passed[i][j][1] || passed[i][j][2] || passed[i][j][3]) {
                    tc ++;
                }
            }
        }
        best = max(best, tc);
        memset(passed, 0, sizeof(passed));
    }

    f0r (i, 0, N) { // Left
        buscar(i, M - 1, 2); // 1 down 3 up
        ll tc = 0;
        f0r (i, 0, N) {
            f0r (j, 0, N) {
                if (passed[i][j][0] || passed[i][j][1] || passed[i][j][2] || passed[i][j][3]) {
                    tc ++;
                }
            }
        }
        best = max(best, tc);
        memset(passed, 0, sizeof(passed));
    }

    f0r (j, 0, M) { // Down
        buscar(0, j, 1); // 1 down 3 up
        ll tc = 0;
        f0r (i, 0, N) {
            f0r (j, 0, N) {
                if (passed[i][j][0] || passed[i][j][1] || passed[i][j][2] || passed[i][j][3]) {
                    tc ++;
                }
            }
        }
        best = max(best, tc);
        memset(passed, 0, sizeof(passed));
    }

    f0r (j, 0, M) { // Up
        buscar(N - 1, j, 3); // 1 down 3 up
        ll tc = 0;
        f0r (i, 0, N) {
            f0r (j, 0, N) {
                if (passed[i][j][0] || passed[i][j][1] || passed[i][j][2] || passed[i][j][3]) {
                    tc ++;
                }
            }
        }
        best = max(best, tc);
        memset(passed, 0, sizeof(passed));
    }

    cout << best << endl;
}