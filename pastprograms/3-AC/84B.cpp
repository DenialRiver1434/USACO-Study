#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int N;
int best[100000];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	/*ifstream fin; ofstream fout;
	fin.open("gravity.in"); fout.open("gravity.out");*/

	cin >> N;
	while ((N % 2) == 0) N /= 2;
	while ((N % 5) == 0) N /= 5;
	f0r (i, 0, N) best[i] = 1000000000;
	
	best[1] = 1;
	deque<tuple<int, int, int>> dq; // mN, m10, sumOfD
	dq.pb(mt(1, 1, 1));

	while(!dq.empty()) {
		int mN, m10, sumOfD;
		tie(mN, m10, sumOfD) = dq.front();
		dq.pop_front();

		if(mN == 0) {
			cout << sumOfD << endl;
			return 0;
		}
		if(best[mN] < sumOfD) continue;

		int pot = (mN * 10) % N;
		if(best[pot] > sumOfD) {
			best[pot] = sumOfD;
			dq.push_front(mt(pot, 0, sumOfD));
		}

		if(m10 != 9) {
			int pot = (mN + 1) % N;
			sumOfD ++;
			if(best[pot] > sumOfD) {
				best[pot] = sumOfD;
				dq.push_back(mt(pot, m10 + 1, sumOfD));
			}
		}
	}
}