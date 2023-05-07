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

struct SegmentTree {
	// Edit below
	lll comb(lll a, lll b) { return a + b; }
	const lll DEFAULT = 0; 
	// Edit above

	vector<lll> segtree;
	lll leng;
	SegmentTree(lll leng) : leng(leng), segtree(leng * 2, DEFAULT) {}

	void set(lll ind, lll val) {
		assert(0 <= ind && ind < leng);
		ind += leng;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind >> 1] = comb(segtree[ind], segtree[ind ^ 1]);
		}
	}

	lll range(lll start, lll end) {
		assert(0 <= start && start < leng && 0 < end && end <= leng);
		lll sum = DEFAULT;
		for (start += leng, end += leng; start < end; start /= 2, end /= 2) {
			if ((start & 1) != 0) { sum = comb(sum, segtree[start++]); }
			if ((end & 1) != 0) { sum = comb(sum, segtree[--end]); }
		}
		return sum;
	}
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int arr_len;
	int query_num;
	cin >> arr_len >> query_num;

	SegmentTree segtree(arr_len);
	for (int i = 0; i < arr_len; i++) {
		int n;
		cin >> n;
		segtree.set(i, n);
	}

	for (int q = 0; q < query_num; q++) {
		int type;
		cin >> type;
		if (type == 1) {
			int ind;
			int val;
			cin >> ind >> val;
			segtree.set(ind - 1, val);
		} else if (type == 2) {
			int start;
			int end;
			cin >> start >> end;
			cout << segtree.range(start - 1, end) << '\n';
		}
	}
}
