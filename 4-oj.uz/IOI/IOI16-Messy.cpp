#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

// For submission, add #include "messy.h"

// For submission remove up to #
V<string> OS;
V<int> permute;

void add_element (string s) {
    OS.pb(s);
}

void compile_set () {
    V<string> opS;
    for (auto s : OS) {
        string os = s;
        f0r (i, 0, len(permute)) {
            os[i] = s[permute[i]];
        }
        opS.pb(os);
    }

    f0r (i, 0, len(OS)) {
        OS[i] = opS[i];
    }
}

bool check_element (string x) {
    for (auto p : OS) {
        if (p == x) return true;
    }
    return false;
}
// #

V<int> restore_permutation (int n, int w, int r) {
    queue<pair<int, int>> q;
    q.push({0, n});
    V<string> binstrings;
    V<tuple<string, int, int>> bases;

    while (!q.empty()) {
        int l = q.front().F, r = q.front().S;
        q.pop();

        ll avg = (l + r) / 2;
        if (r - l == 1) {
            continue;
        }

        string base;
        f0r (i, 0, l) base += '1';
        f0r (i, l, r) base += '0';
        f0r (i, r, n) base += '1';
        bases.pb({base, l, r});

        f0r (i, avg, r) {
            string alt = base;
            alt[i] = '1';
            binstrings.pb(alt);
        }

        q.push({avg, r});
        q.push({l, avg});
    }
    
    for (auto b : binstrings) {
        add_element(b);
    }
    compile_set();

    map<string, string> baseconv;
    string all0, all1;
    f0r (i, 0, n) {
        all0 += '0';
        all1 += '1';
    }
    baseconv[all0] = all0;

    V<int> ans(n, 0);

    for (auto b : bases) {
        string base = get<0>(b);
        int l = get<1>(b), r = get<2>(b);
        int midp = (r + l) / 2;

        string convbase = baseconv[base];
        string norm = convbase; // 000111
        string antinorm = convbase; // 111000

        f0r (i, 0, n) {
            if (convbase[i] == '1') continue;

            string alt = convbase;
            alt[i] = '1';
            
            if (check_element(alt)) {
                norm[i] = '1';
                ans[i] += (r - midp);
            } else {
                antinorm[i] = '1';
            }
        }

        string normbase = base, antibase = base;
        f0r (i, midp, r) normbase[i] = '1';
        f0r (i, l, midp) antibase[i] = '1';

        baseconv[normbase] = norm;
        baseconv[antibase] = antinorm;
    }

    return ans;
}

// Remove int main () if submitting to oj.uz

int main () {
    ll N;
    cin >> N;

    f0r (i, 0, N) {
        ll a; cin >> a;
        permute.pb(a);
    }

    V<int> output = restore_permutation(N, 0, 0);
    for (auto o : output) {
        cout << o << endl;
    }
}