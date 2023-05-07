#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> lengths;
string read;

bool test (int val) {
	int gathered = 0, count = 1;
	for (auto l : lengths) {
		if((gathered + l) > val) {
			count ++;
			gathered = l;
		}
		else gathered += l;
	}
	return (count <= N);
}

int first_true(int lo, int hi) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}
int main() {
	ifstream fin; fin.open("shuffle.in");
	fin >> N;
	int left = 0;
	while (fin >> read) {
		int prev = 0;
		for (auto r : read) {
			if(r == '-') {
				left = max(left, prev);
				lengths.pb(prev + 1);
				prev = 0;
			}
			else prev ++;
		}
		lengths.pb(prev + 1);
	}
	lengths[lengths.size() - 1] --;
	for (auto l : lengths) left = max(left, l);
	cout << first_true(left, 1e6) << endl;
}