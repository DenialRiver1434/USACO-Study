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
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename T> istream& operator>>(istream& in, pair<T, T>& a) {in >> a.F >> a.S; return in;};
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ' ' << a.S << endl; return out;};

#define ld long double
const ld EPS = 1E-18;

struct Point {
	ld x, y;

	bool operator<(const Point &p) const {
		return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
	}
};

struct Line {
	ld a, b, c;

	Line() {}
	Line(Point p, Point q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = -a * p.x - b * p.y;
		norm();
	}

	void norm() {
		ld z = sqrt(a * a + b * b);
		if (abs(z) > EPS) { a /= z, b /= z, c /= z; }
	}

	ld dist(Point p) const { return a * p.x + b * p.y + c; }
};

ld det(ld a, ld b, ld c, ld d) { return a * d - b * c; }

inline bool betw(ld l, ld r, ld x) {
	return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

inline bool intersect_1d(ld a, ld b, ld c, ld d) {
	if (a > b) { swap(a, b); }
	if (c > d) { swap(c, d); }
	return max(a, c) <= min(b, d) + EPS;
}

bool intersect(Point a, Point b, Point c, Point d, Point &left, Point &right) {
	if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y)) {
		return false;
	}
	Line m(a, b);
	Line n(c, d);
	ld zn = det(m.a, m.b, n.a, n.b);
	if (abs(zn) < EPS) {
		if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS) { return false; }
		if (b < a) { swap(a, b); }
		if (d < c) { swap(c, d); }
		left = max(a, c);
		right = min(b, d);
		return true;
	} else {
		ld det_x = det(m.c, m.b, n.c, n.b) / zn;
		ld det_y = det(m.a, m.c, n.a, n.c) / zn;
		left.x = right.x = (det_x == 0 ? 0 : -det_x);
		left.y = right.y = (det_y == 0 ? 0 : -det_y);
		return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
		       betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
	}
}

V<pair<pair<ld, ld>, pair<ld, ld>>> segs;
V<tuple<pair<ld, ld>, bool, ll>> endpoints;

bool cmp (pair<ld, ld> a, pair<ld, ld> b) {
    if (abs(a.first - b.first) < EPS) {
        return a.second < b.second;
    } 
    return a.first < b.first;
}

bool cmpy (tuple<ld, ld, ll> a, tuple<ld, ld, ll> b) {
    if (abs(get<1>(a) - get<1>(b)) < EPS) {
        return get<0>(a) < get<0>(b);
    } 
    return get<1>(a) < get<1>(b);
}

set<tuple<ld, ld, ll>, decltype(cmpy)*> active(cmpy);

int main () {
    fileread("cowjump");

    ll N; fin >> N;
    f0r (i, 0, N) {
        ll a, b, c, d; fin >> a >> b >> c >> d;
        pair<ld, ld> e1 = {a, b};
        pair<ld, ld> e2 = {c, d};
        if (cmp(e2, e1)) {
            swap(e1, e2);
        }
        segs.pb({e1, e2});
        endpoints.pb({e1, 0, i});
        endpoints.pb({e2, 1, i});
    }

    sort(endpoints.begin(), endpoints.end());
    ll crit1, crit2;
    for (auto e : endpoints) {
        pair<ld, ld> point;
        bool typ;
        ll ind;
        tie(point, typ, ind) = e;
        
        if (!typ) {
            active.is({point.F, point.S, ind});
        } else {
            auto st = segs[ind].F;
            auto itr = active.find({st.F, st.S, ind});
            if (itr != active.begin()) {
                Point a = {st.F, st.S};
                Point b = {point.F, point.S};
                auto itrprime = prev(itr);
                ll indprime = get<2>(*itrprime);
                Point c = {segs[indprime].F.F, segs[indprime].F.S};
                Point d = {segs[indprime].S.F, segs[indprime].S.S};
                Point x, y;
                if (intersect(a, b, c, d, x, y)) {
                    crit1 = indprime; crit2 = ind;
                    break;
                }
            }
            if (next(itr) != active.end()) {
                Point a = {st.F, st.S};
                Point b = {point.F, point.S};
                auto itrprime = next(itr);
                ll indprime = get<2>(*itrprime);
                Point c = {segs[indprime].F.F, segs[indprime].F.S};
                Point d = {segs[indprime].S.F, segs[indprime].S.S};
                Point x, y;
                if (intersect(a, b, c, d, x, y)) {
                    crit1 = indprime; crit2 = ind;
                    break;
                }
            }

            active.erase(itr);
        }
    }
    
    ll intc = 0;
    f0r (i, 0, N) {
        if (i == crit1) continue;
        
        Point a = {segs[crit1].F.F, segs[crit1].F.S};
        Point b = {segs[crit1].S.F, segs[crit1].S.S};
        Point c = {segs[i].F.F, segs[i].F.S};
        Point d = {segs[i].S.F, segs[i].S.S}, x, y;
        if (intersect(a, b, c, d, x, y)) {
            intc ++;
        }
    }
    if (intc > 1) {
        fout << crit1 + 1 << endl;
    } else {
        fout << crit2 + 1 << endl;
    }
}