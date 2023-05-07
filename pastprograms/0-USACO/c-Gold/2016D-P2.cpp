#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

/*
On H
     G0 G1  G2
     ---------
H1 | 0  X   X
H2 | 1  
H3 | X  X

On G
*/

ll dist (pair<ll, ll> a, pair<ll, ll> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("checklist.in"); fout.open("checklist.out");

	ll H, G; fin >> H >> G;
	ll OnH[H + 1][G + 1], OnG[H + 1][G + 1];
	f0r (i, 0, H + 1) {
		f0r (j, 0, G + 1) {
			OnH[i][j] = 1e17;
			OnG[i][j] = 1e17;
		}
	}
	OnH[1][0] = 0;

	vector<pair<ll, ll>> Hs = {{-1e8, -1e8}}, Gs = {{-1e8, -1e8}};
	f0r (i, 0, H) {
		ll a, b; fin >> a >> b;
		Hs.pb(mp(a, b));
	}
	f0r (i, 0, G) {
		ll a, b; fin >> a >> b;
		Gs.pb(mp(a, b));
	}

	f0r (i, 1, H + 1) {
		f0r (j, 0, G + 1) {
			if(i == 1 && j == 0) continue;
			// Increment i / H
			OnH[i][j] = min(OnH[i][j], OnH[i - 1][j] + dist(Hs[i], Hs[i - 1])); 
			OnH[i][j] = min(OnH[i][j], OnG[i - 1][j] + dist(Hs[i], Gs[j])); 
			if (j > 0) {
				OnG[i][j] = min(OnG[i][j], OnH[i][j - 1] + dist(Gs[j], Hs[i])); 
				OnG[i][j] = min(OnG[i][j], OnG[i][j - 1] + dist(Gs[j], Gs[j - 1])); 
			}
		}
	}
	fout << OnH[H][G] << endl;
}