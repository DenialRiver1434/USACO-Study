#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (lll i = begin; i < n; i ++)
#define len(x) x.size()
#define vl vector<lll>
#define sl set<lll>
#define msl multiset<lll>
#define pl pair<lll, lll>
#define vpl vector<pair<lll, lll>>
#include <bits/stdc++.h>
using namespace std;

lll N, M, l = 0, tas = 0, bs = 1e18;
vpl meals;
msl spicy;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
    ifstream fin; ofstream fout;
	fin.open("hayfeast.in"); fout.open("hayfeast.out");

	fin >> N >> M;
	f0r (i, 0, N) {
		lll tast, spic; fin >> tast >> spic;
		tas += tast;
		spicy.is(spic);
		meals.pb(mp(tast, spic));

		if(tas >= M) {
			while ((tas - meals[l].first) >= M) {
				tas -= meals[l].first;
				spicy.erase(spicy.find(meals[l].second));
				l ++;
			}
			bs = min(bs, *spicy.rbegin());
		}
	}
	fout << bs << endl;
}
