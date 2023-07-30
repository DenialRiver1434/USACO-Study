#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define INF 1000000000000000000
#define IINF 1000000000
#define MOD 1000000007
#define len(x) x.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr);
#include <bits/stdc++.h> 
using namespace std;

queue<pair<ll, bool>> q; // 0 = bessie, 1 = elsie
vector<tuple<ll, ll, ll>> pies[2];
ll N, D, dist[2][100000];

set<pair<ll, ll>> filled[2];

ll first_true (bool typ, ll x) {
	ll lo = 0, hi = N;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (get<0>(pies[typ][mid]) >= x) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

ll last_true(bool typ, ll x) {
	ll lo = -1, hi = N - 1;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;
		if (get<0>(pies[typ][mid]) <= x) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int main () {
    ifstream fin; fin.open("piepie.in");
    ofstream fout; fout.open("piepie.out");

    fin >> N >> D;
    f0r (i, 0, N) {
        ll a, b; fin >> a >> b;
        pies[0].pb({b, a, i});
    }
    f0r (i, 0, N) {
        ll a, b; fin >> a >> b;
        pies[1].pb({a, b, i});
    }
    filled[0].is({-INF, -INF}); filled[1].is({-INF, -INF});
    filled[0].is({INF, INF}); filled[1].is({INF, INF});
    sort(pies[0].begin(), pies[0].end());
    sort(pies[1].begin(), pies[1].end());
    f0r (i, 0, N) {
        ll a, b, j;
        tie(b, a, j) = pies[0][i];
        if(b == 0) {
            q.push({i, 0});
            dist[0][i] = 1;
            filled[0].is({i, i + 1});
        }
        else {
            dist[0][i] = IINF;
        }
        tie(b, a, j) = pies[1][i];
        if(b == 0) {
            q.push({i, 1});
            dist[1][i] = 1;
            filled[1].is({i, i + 1});
        }
        else {
            dist[1][i] = IINF;
        }
    }

    while (!q.empty()) {
        ll pos, curdist, lob, upb;
        bool typ; 
        tie(pos, typ) = q.front();
        curdist = dist[typ][pos];
        q.pop();

        typ = !typ;
        ll tub = get<1>(pies[!typ][pos]);
        upb = last_true(typ, tub);
        lob = first_true(typ, tub - D);
        if(upb == -1) continue;
        
        auto itr = filled[typ].lb({lob, -1});
        upb ++;
        ll newstart, newend;
        auto itrlow = filled[typ].lb({lob, INF + 1});
        itrlow = prev(itrlow);
        if((*itrlow).second < lob) {
            itrlow = next(itrlow);
        }
        newstart = min(lob, (*itrlow).first);
        if(newstart < (*itrlow).first) {
            f0r (j, newstart, min(upb, (*itrlow).first)) {
                dist[typ][j] = curdist + 1;
                q.push({j, typ});
            }
        }

        auto itrhi = filled[typ].lb({upb, INF + 1});
        itrhi = prev(itrhi);
        newend = max(upb, (*itrhi).second);
        ll previous = -1;

        while (itrlow != filled[typ].end()) {
            if(previous != -1) {
                f0r (j, previous, min(upb, (*itrlow).first)) {
                    dist[typ][j] = curdist + 1;
                    q.push({j, typ});
                }
            }
            if((*itrlow).second > newend) break;

            previous = (*itrlow).second;

            itrlow = next(itrlow);
            filled[typ].erase(prev(itrlow));
        }
        filled[typ].is({newstart, newend});
    }

    ll ans[100000];
    f0r (i, 0, N) {
        ll realpos = get<2>(pies[0][i]);
        if(dist[0][i] != IINF) ans[realpos] = dist[0][i];
        else ans[realpos] = -1; 
    }
    f0r (i, 0, N) {
        fout << ans[i] << endl;
    }
}