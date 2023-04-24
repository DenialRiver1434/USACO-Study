#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define lll long long
#define vi vector<lll>
#define f0r(i, begin, end) for (lll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

lll N, Q, baseline = 0, newpos[150000];
vi sumto;
vector<pair<lll, lll>> nums; 

lll first_true(lll tgt) {
	lll lo = 0, hi = N;
	while (lo < hi) {
		lll mid = lo + (hi - lo) / 2;
		if (nums[mid].first <= tgt) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N;
	f0r (i, 0, N) {
		lll a; cin >> a;
		nums.pb(mp(a, i));
	}
	sort(nums.begin(), nums.end(), greater<pair<lll, lll>>());
	lll pref = 0;
	f0r (i, 0, N) {
		pref += nums[i].first; baseline += pref;
		sumto.pb(pref);
		newpos[nums[i].second] = i;
	}
	cin >> Q;
	f0r (i, 0, Q) {
		lll pos, res; cin >> pos >> res;
		pos = newpos[pos - 1];
		lll val = nums[pos].first;
		lll cur = baseline;
		// removal
		cur -= (N - pos - 1) * (val); // The -1 is necessary as the prefix sum in the next step removes val once more
		cur -= sumto[pos];

		// addition
		lll npos = first_true(res);
		if(res < val) cur += (N - npos + 1) * res;
		else cur += (N - npos) * res;

		npos --;
		if(res < val) {
			cur += sumto[npos];
			cur -= val;
		}
		else if (npos >= 0) {
			cur += sumto[npos];
		}
		cout << cur << endl;
	}
}