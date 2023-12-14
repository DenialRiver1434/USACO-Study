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

const ll A = 257274504162904133, B = 1720921529140328231;
ll powmod2[205], powmod5[205];
string S;
 
ll modmul (ll a, ll b) {
    __int128_t xa = a, xb = b;
    ll xm = (xa * xb) % B;
    if(xm < 0) xm += B;
    return xm;
}

bool dest[200][200];
ll N, M;

char grid[200][200];

void displaygrid () {
    f0r (i, 0, N) {
        f0r (j, 0, M) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

ll getval () {
    ll tc = 0;
    f0r (i, 0, N) {
        f0r (j, 0, M) {
            if (grid[i][j] == 'O') {
                tc += N - i;
            }
        }
    }
    return tc;
}

ll gethsh () {
    ll tc = 0;
    f0r (i, 0, N) {
        f0r (j, 0, M) {
            if (grid[i][j] == 'O') {
                tc += modmul(modmul(powmod2[i], powmod5[j]), 213);
            }
        }
    }
    return tc;
}

void shake () {
    // North
    memset(dest, 0, sizeof(dest));
    f0r (j, 0, M) {
        ll passed = 0;
        ll last = -1;
        f0r (i, 0, N) {
            if (grid[i][j] == '#') {
                last = i;
                passed = 0;
            }
            else if (grid[i][j] == 'O') {
                dest[passed + last + 1][j] = 1;
                passed ++;
            }
        }
    }

    f0r (i, 0, N) {
        f0r (j, 0, M) {
            if (dest[i][j]) {
                grid[i][j] = 'O';
            }
            else if (grid[i][j] != '#') {
                grid[i][j] = '.';
            }
        }
    }

    // West
    memset(dest, 0, sizeof(dest));
    f0r (i, 0, N) {
        ll passed = 0;
        ll last = -1;
        f0r (j, 0, M) {
            if (grid[i][j] == '#') {
                last = j;
                passed = 0;
            }
            else if (grid[i][j] == 'O') {
                dest[i][passed + last + 1] = 1;
                passed ++;
            }
        }
    }

    f0r (i, 0, N) {
        f0r (j, 0, M) {
            if (dest[i][j]) {
                grid[i][j] = 'O';
            }
            else if (grid[i][j] != '#') {
                grid[i][j] = '.';
            }
        }
    }

    // South
    memset(dest, 0, sizeof(dest));
    f0r (j, 0, M) {
        ll passed = 0;
        ll last = N;
        For (i, N - 1, -1) {
            if (grid[i][j] == '#') {
                last = i;
                passed = 0;
            }
            else if (grid[i][j] == 'O') {
                dest[last - passed - 1][j] = 1;
                passed ++;
            }
        }
    }

    f0r (i, 0, N) {
        f0r (j, 0, M) {
            if (dest[i][j]) {
                grid[i][j] = 'O';
            }
            else if (grid[i][j] != '#') {
                grid[i][j] = '.';
            }
        }
    }

    // East
    memset(dest, 0, sizeof(dest));
    f0r (i, 0, N) {
        ll passed = 0;
        ll last = M;
        For (j, M - 1, -1) {
            if (grid[i][j] == '#') {
                last = j;
                passed = 0;
            }
            else if (grid[i][j] == 'O') {
                dest[i][last - passed - 1] = 1;
                passed ++;
            }
        }
    }

    f0r (i, 0, N) {
        f0r (j, 0, M) {
            if (dest[i][j]) {
                grid[i][j] = 'O';
            }
            else if (grid[i][j] != '#') {
                grid[i][j] = '.';
            }
        }
    }
}

int main () {
    powmod2[0] = powmod5[0] = 1;
    f0r (i, 1, 205) {
        powmod2[i] = modmul(powmod2[i - 1], A);
        powmod5[i] = modmul(powmod5[i - 1], 23198231983981ll);
    }

    ifstream fin; fin.open("lineup.in");
    string r;
    ll tc = 0; 
    while (fin >> r) {
        M = len(r);
        f0r (j, 0, M) {
            grid[N][j] = r[j];
        }
        N ++;
    }
    
    ll modn;

    map<ll, ll> past;
    past[gethsh()] = 0;
    f0r (i, 1, 1000) {
        shake();
        ll chsh = gethsh();
        if (past.find(chsh) != past.end()) {
            displaygrid();
            ll modn = i - past[chsh];
            ll nec = (1000000000 - i) % modn;
            
            f0r (i, 0, nec) {
                shake();
            }

            cout << getval() << endl;
            break;
        }
        past[gethsh()] = i;
    }
}