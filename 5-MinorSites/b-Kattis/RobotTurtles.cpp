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
#define f0r(i, begin, fin) for (ll i = begin; i < fin; i ++) 
#define For(i, fin, begin) for (ll i = fin - 1; i >= begin; i --) 
#define all(x) x.begin(), x.fin()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

// 0 = up, 1 = right, 2 = down, 3 = left
pair<int, int> fin;
V<tuple<int, int, int, int>> conn[8][8][4];
int dist[8][8][4];
tuple<int, int, int> source[8][8][4];
set<pair<int, int>> icebergs;

int main () {
    f0r (i, 0, 8) {
        f0r (j, 0, 8) {
            char a; cin >> a;
            if (a == 'D') {
                fin = {i, j};
            }
            if (a == 'D' || a == '.') {
                if (i > 0) {
                    conn[i - 1][j][2].pb({i, j, 2, 1});
                }
                if (j > 0) {
                    conn[i][j - 1][1].pb({i, j, 1, 1});
                }
                if (i < 7) {
                    conn[i + 1][j][0].pb({i, j, 0, 1});
                }
                if (j < 7) {
                    conn[i][j + 1][3].pb({i, j, 3, 1});
                }
            }
            if (a == 'I') {
                icebergs.is({i, j});
                if (i > 0) {
                    conn[i - 1][j][2].pb({i, j, 2, 2});
                }
                if (j > 0) {
                    conn[i][j - 1][1].pb({i, j, 1, 2});
                }
                if (i < 7) {
                    conn[i + 1][j][0].pb({i, j, 0, 2});
                }
                if (j < 7) {
                    conn[i][j + 1][3].pb({i, j, 3, 2});
                }
            }
            
            conn[i][j][0].pb({i, j, 3, 1});
            conn[i][j][0].pb({i, j, 1, 1});
            dist[i][j][0] = inf;
            
            conn[i][j][1].pb({i, j, 0, 1});
            conn[i][j][1].pb({i, j, 2, 1});
            dist[i][j][1] = inf;
            
            conn[i][j][2].pb({i, j, 1, 1});
            conn[i][j][2].pb({i, j, 3, 1});
            dist[i][j][2] = inf;

            conn[i][j][3].pb({i, j, 2, 1});
            conn[i][j][3].pb({i, j, 0, 1});
            dist[i][j][3] = inf;
        }
    }
	
	using T = pair<int, tuple<int, int, int>>;
	priority_queue<T, vector<T>, greater<T>> pq;
	dist[7][0][1] = 0; 
	pq.push({0, {7, 0, 1}});

    int findist = inf;
    tuple<int, int, int> finpos;
	while (pq.size()) {
		int cdist = pq.top().F;
		int x, y, dir;
		tie(x, y, dir) = pq.top().S;
		pq.pop();

		if (cdist != dist[x][y][dir]) continue;
        if ((x == fin.F && y == fin.S) && (cdist < findist)) {
            findist = cdist;
            finpos = {x, y, dir};
        }
		for (auto i : conn[x][y][dir]) {
			if (cdist + get<3>(i) < dist[get<0>(i)][get<1>(i)][get<2>(i)]) {
				pq.push({dist[get<0>(i)][get<1>(i)][get<2>(i)] = cdist + get<3>(i), {get<0>(i), get<1>(i), get<2>(i)}});
                source[get<0>(i)][get<1>(i)][get<2>(i)] = {x, y, dir};
			}
		}
	}
    if(findist == inf) {
        cout << "no solution" << endl;
        return 0;
    }
    
    auto nxt = finpos;
    finpos = source[get<0>(finpos)][get<1>(finpos)][get<2>(finpos)];
    string ans = "";
    while (nxt != make_tuple(7, 0, 1)) {
        int x, y, dir, px, py, pdir; 
        tie(x, y, dir) = finpos; tie(px, py, pdir) = nxt;

        if (((pdir - dir + 4) % 4) == 1) {
            ans = 'R' + ans;
        }
        else if (((pdir - dir + 4) % 4) == 3) {
            ans = 'L' + ans;
        }
        else {
            if(icebergs.find({px, py}) != icebergs.end()) {
                ans = "XF" + ans;
            }
            else {
                ans = "F" + ans;
            }
        }

        nxt = finpos;
        finpos = source[x][y][dir];
    }
    cout << ans << endl;
}