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

// '/' = 1, '\' = 0
ll N, startx, starty, finx, finy, tot = 0;
V<V<pair<ll, bool>>> rowmirror, colmirror;

// 0 - 1 typline, 0 = hori, 1 = vert
V<set<PL>> expt[2][2];

// 0 = up, 1 = right, 2 = down, 3 = left
tuple<ll, ll, ll, bool> npos (ll x, ll y, ll dir) {
    if (dir == 1) { // y stays the same, x ++
        ll pos = lower_bound(all(colmirror[y]), make_pair(x, false)) - colmirror[y].begin();
        if (pos == len(colmirror[y]) - 1) {
            return {N, y, dir, 0};
        }
        ll nx = colmirror[y][pos + 1].F; bool ndir = colmirror[y][pos + 1].S;
        if (ndir) {
            return {nx, y, 0, 1};
        }
        return {nx, y, 2, 1};
    }
    else if (dir == 3) {
        ll pos = lower_bound(all(colmirror[y]), make_pair(x, false)) - colmirror[y].begin();
        if (pos == 0) {
            return {-1, y, dir, 0};
        }
        ll nx = colmirror[y][pos - 1].F; bool ndir = colmirror[y][pos - 1].S;
        if (ndir) {
            return {nx, y, 2, 1};
        }
        return {nx, y, 0, 1};
    }
    else if (dir == 0) { // x stays the same
        ll pos = lower_bound(all(rowmirror[x]), make_pair(y, false)) - rowmirror[x].begin();
        if (pos == len(rowmirror[x]) - 1) {
            return {x, N, dir, 0};
        }
        ll ny = rowmirror[x][pos + 1].F; bool ndir = rowmirror[x][pos + 1].S;
        if (ndir) {
            return {x, ny, 1, 1};
        }
        return {x, ny, 3, 1};
    }
    else {
        ll pos = lower_bound(all(rowmirror[x]), make_pair(y, false)) - rowmirror[x].begin();
        if (pos == 0) {
            return {x, -1, dir, 0};
        }
        ll ny = rowmirror[x][pos - 1].F; bool ndir = rowmirror[x][pos - 1].S;
        if (ndir) {
            return {x, ny, 3, 1};
        }
        return {x, ny, 1, 1};
    }
}

struct SegmentTree {
	vector<ll> segtree;
	ll leng;
	
	// Edit below
	ll comb(ll a, ll b) { return a + b; }
	const ll DEFAULT = 0; 
	// Edit above
 
	SegmentTree(ll N) {
        leng = N;
        f0r (i, 0, 2 * N) {
            segtree.pb(DEFAULT);
        }
    }
 
	void set(ll ind, ll val) {
		ind += leng;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind >> 1] = comb(segtree[ind], segtree[ind ^ 1]);
		}
	}
 
	ll range(ll start, ll end) {
		ll sum = DEFAULT;
		for (start += leng, end += leng; start < end; start /= 2, end /= 2) {
			if ((start & 1) != 0) { sum = comb(sum, segtree[start++]); }
			if ((end & 1) != 0) { sum = comb(sum, segtree[--end]); }
		}
		return sum;
	}
};

int main () {
    fileread("optics");

    fin >> N >> finx >> finy;
    N += 2;
    f0r (i, 0, N) {
        rowmirror.pb({});
        colmirror.pb({});
    }

    V<tuple<ll, ll, bool>> mirrors;
	vector<ll> xs, ys;
    xs.pb(0); xs.pb(finx);
    ys.pb(0); ys.pb(finy);
    mirrors.pb({0, 0, 0});
    mirrors.pb({finx, finy, 0});

    f0r (i, 0, N - 2) {
        ll px, py; char typ;
        fin >> px >> py >> typ;
        xs.pb(px); ys.pb(py);
        mirrors.pb({px, py, typ == '/'});
    }
	sort(all(xs));
	sort(all(ys));

    f0r (i, 0, N) {
        ll px, py; char typ;
        tie(px, py, typ) = mirrors[i];
        mirrors[i] = {lower_bound(all(xs), px) - xs.begin(), lower_bound(all(ys), py) - ys.begin(), typ};
        if (px == 0 && py == 0) {
            startx = lower_bound(all(xs), px) - xs.begin();
            starty = lower_bound(all(ys), py) - ys.begin();
        }
        if (px == finx && py == finy) {
            finx = lower_bound(all(xs), px) - xs.begin();
            finy = lower_bound(all(ys), py) - ys.begin();
        }
    }

    for (auto m : mirrors) {
        ll px, py; bool typ;
        tie(px, py, typ) = m;
        rowmirror[px].pb({py, typ});
        colmirror[py].pb({px, typ});
    }

    f0r (i, 0, N) {
        sort(all(rowmirror[i]));
        sort(all(colmirror[i]));
        expt[0][0].pb({});
        expt[0][1].pb({});
        expt[1][0].pb({});
        expt[1][1].pb({});
    }

    ll x = startx, y = starty, dir = 0;
    while (true) {
        ll nx, ny, ndir; bool success;
        tie (nx, ny, ndir, success) = npos(x, y, dir);

        if (dir == 0 || dir == 2) {
            expt[0][1][x].is({min(y, ny), max(y, ny)});
        }
        else {
            expt[0][0][y].is({min(x, nx), max(x, nx)});
        }
        
        x = nx; y = ny; dir = ndir;
        if (!success) break;
    }

    f0r (xdir, 0, 4) {
        ll x = finx, y = finy, dir = xdir;
        while (true) {
            ll nx, ny, ndir; bool success;
            tie (nx, ny, ndir, success) = npos(x, y, dir);

            if (dir == 0 || dir == 2) {
                expt[1][1][x].is({min(y, ny), max(y, ny)});
            }
            else {
                expt[1][0][y].is({min(x, nx), max(x, nx)});
            }
            
            if (nx == finx && ny == finy) {
                break;
            }
            x = nx; y = ny; dir = ndir;
            if (!success) break;
        }
    }
    
    // [0][0] and [1][1]
    V<V<ll>> stas(N + 1), fins(N + 1);
    f0r (i, 0, N) {
        for (PL x : expt[1][1][i]) {
            stas[x.F + 1].pb(i);
            fins[x.S].pb(i);
        }
    }

    SegmentTree segtree(N);
    f0r (i, 0, N) {
        for (auto s : stas[i]) {
            segtree.set(s, segtree.range(s, s + 1) + 1);
        }
        for (auto s : fins[i]) {
            segtree.set(s, segtree.range(s, s + 1) - 1);
        }
        for (auto pa : expt[0][0][i]) {
            tot += segtree.range(pa.F + 1, pa.S);
        }
    }

    // [0][1] and [1][0]
    V<V<ll>> stas2(N + 1), fins2(N + 1);
    f0r (i, 0, N) {
        for (PL x : expt[1][0][i]) {
            stas2[x.F + 1].pb(i);
            fins2[x.S].pb(i);
        }
    }

    SegmentTree segtree2(N);
    f0r (i, 0, N) {
        for (auto s : stas2[i]) {
            segtree2.set(s, segtree2.range(s, s + 1) + 1);
        }
        for (auto s : fins2[i]) {
            segtree2.set(s, segtree2.range(s, s + 1) - 1);
        }
        for (auto pa : expt[0][1][i]) {
            tot += segtree2.range(pa.F + 1, pa.S);
        }
    }

    fout << tot << endl;
}