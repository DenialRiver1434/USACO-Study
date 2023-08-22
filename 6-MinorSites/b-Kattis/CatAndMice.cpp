#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define V vector
#define MS multiset
#define PL pair<double, double>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define For(i, end, begin) for (int i = end - 1; i >= begin; i --) 
#define aint(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (int)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nuintptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;}; 

const int MAX_N = 15;

int N;
double fastest[1 << MAX_N][MAX_N], factor;
V<tuple<double, double, double>> mice;

double dist (PL a, PL b) {
    return sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}

bool is_valid (int i, int j) {
    return abs(fastest[i][j] - 1e9) > 1e-5;
}

bool test (double x) {
    f0r (i, 0, N) {
        fastest[0][i] = 0;
    }
    f0r (i, 1, 1 << N) {
        f0r (j, 0, N) {
            fastest[i][j] = 1e9;
        }
    }
    f0r (i, 0, N) {
        if ((get<2>(mice[i]) * x) > dist({0, 0}, {get<0>(mice[i]), get<1>(mice[i])})) {
            fastest[1 << i][i] = dist({0, 0}, {get<0>(mice[i]), get<1>(mice[i])}) / x;
        }
    }

    f0r (i, 0, 1 << N) {
        f0r (j, 0, N) {
            if (is_valid(i, j)) continue;
            if(((1 << j) & i) == 0) continue;

            int alt = i - (1 << j);
            double newx = x * pow(factor, __builtin_popcount(alt));
            f0r (k, 0, N) {
                if (!is_valid(alt, k)) continue;
                if(((1 << k) & alt) == 0) continue;
                double time = dist({get<0>(mice[j]), get<1>(mice[j])}, {get<0>(mice[k]), get<1>(mice[k])}) / newx;
                if ((fastest[alt][k] + time) < get<2>(mice[j])) {
                    fastest[i][j] = min(fastest[i][j], fastest[alt][k] + time);
                }
            }
        }
    }

    bool ok = 0;
    f0r (i, 0, N) {
        if(is_valid((1 << N) - 1, i)) ok = 1;
    }
    return ok;
}

double first_true(double lo, double hi) {
	f0r (i, 0, 64) {
		double mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return lo;
}

int main () {
    cin >> N;
    f0r (i, 0, N) {
        double a, b, c; cin >> a >> b >> c;
        mice.pb({a, b, c});
    }
    cin >> factor;
    cout << setprecision(20) << first_true(0, 1e6) << endl;
}