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

const V<char> order = {'A', 'K', 'Q', 'T', '9', '8', '7', '6', '5', '4', '3', '2', 'J'};
map<char, ll> worth;

struct Bet {
    string hand; ll bet;
};

ll gtyp (string x) {
    ll ms = 0, jc = 0;
    map<char, ll> cnt;
    for (auto ch : x) {
        if (ch == 'J') {
            jc ++;
        }
        else { ms = max(ms, ++cnt[ch]); }
    }
    ms += jc;
    if (ms == 5) {
        return 7;
    }
    else if (ms == 4) {
        return 6;
    }
    else if (ms == 3 && len(cnt) == 2) {
        return 5;
    }
    else if (ms == 3) {
        return 4;
    }
    else if (ms == 2 && len(cnt) == 3) {
        return 3;
    }
    else if (ms == 2) {
        return 2;
    }
    else return 1;
}

bool cmp (const Bet a, const Bet b) {
    ll atyp = gtyp(a.hand), btyp = gtyp(b.hand);
    if (atyp == btyp) {
        f0r (i, 0, 5) {
            if (worth[(a.hand)[i]] == worth[(b.hand)[i]]) continue;
            return worth[(a.hand)[i]] < worth[(b.hand)[i]];
        }
    }
    return atyp > btyp; 
}

int main () {
    f0r (i, 0, len(order)) {
        worth[order[i]] = i;
    }

    V<Bet> inps;
    ll N; cin >> N;
    f0r (i, 0, N) {
        string x; ll a; cin >> x >> a;
        inps.pb({x, a});
    }

    sort(all(inps), cmp);
    reverse(all(inps));
    ll tc = 0;
    f0r (i, 0, N) {
        tc += (i + 1) * inps[i].bet;
    }
    cout << tc << endl;
}