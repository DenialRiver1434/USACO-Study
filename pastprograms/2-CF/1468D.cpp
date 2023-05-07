#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int T, N, M, a, b, c;
multiset<int> firecrackers;

int main() {
	cin >> T;
	while (T --) {
		cin >> N >> M >> a >> b;
		if((--a) > (--b)) {a = N - a - 1; b = N - b - 1;}
		firecrackers.clear();
		for (int i = 0; i < M; i ++) {
			cin >> c;
			firecrackers.is(c);
		}
		int maxdrop = b - a - 1;
		int time = b - 1;
		int count = 0;
		while (maxdrop) {
			auto pos = firecrackers.lower_bound(time - count);
			if(*pos == (time - count)) {
				count ++;
				maxdrop --;
				continue;
			}
			if(pos == firecrackers.begin()) break;
			pos --;
			firecrackers.erase(firecrackers.find(*pos));
			count ++; maxdrop --;
		}
		cout << count << endl;
	}
}