#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

vector<int> conn[200000];
const int MOD = 1e9 + 7;

int tc () {
	int N; cin >> N;
	string ar, br; cin >> ar >> br;
	vector<int> a = {0}, b = {0}, acorrespond = {}, bcorrespond = {};
	int A = 0, B = 0;
	for (char ch : ar) {
		if(int(ch) == 43) a.pb(-1);
		else if(int(ch) == 49) continue;
		else a.pb(int(ch) - 48);
		A ++;
	}
	for (char ch : br) {
		if(int(ch) == 43) b.pb(-1);
		else if(int(ch) == 49) continue;
		else b.pb(int(ch) - 48);
		B ++;
	}
	
	int prev = 1;
	for (auto ac : a) {
		prev += (ac == -1);
		if(ac == 0) prev = 1;
		acorrespond.pb(prev);
	}
	prev = 1;
	for (auto bc : b) {
		prev += (bc == -1);
		if(bc == 0) prev = 1;
		bcorrespond.pb(prev);
	}

	int count[A + 1][B + 1];
	f0r (i, 0, A + 1) count[i][0] = 1;
	f0r (i, 0, B + 1) count[0][i] = 1;
	f0r (i, 1, A + 1) {
		f0r (j, 1, B + 1) {
			if (a[i] == 0) count[i][j] = bcorrespond[j];
			else if (b[j] == 0) count[i][j] = acorrespond[i];
			else {
				if(a[i] == -1 && b[j] == -1) {
					count[i][j] = count[i - 1][j] + count[i][j - 1] - count[i - 1][j - 1];
				}
				else if(a[i] > -1 && b[j] > -1) {
					count[i][j] = count[i - 1][j] + count[i][j - 1] - count[i - 1][j - 1];
				}
				else {
					count[i][j] = count[i - 1][j] + count[i][j - 1];
				}
			}
			if(count[i][j] < 0) {
				count[i][j] += MOD;
				if(count[i][j] < 0) count[i][j] += MOD;
			}
			count[i][j] %= (MOD);
			if(count[i][j] < 0) {
				cout << i << " : " << j << " / " << count[i][j] << endl;
			}
		}
	}
	return count[A][B];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	int T; cin >> T;
	while (T --) {
		cout << tc () << endl;
	}
}
