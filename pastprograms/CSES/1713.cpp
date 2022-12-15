#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main () {
	int N;
	cin >> N;
	while (N --) {
		int total = 1, tester = 2, x;
		cin >> x;
		while (x != 1) {
			bool found = false;
			while ((tester * tester) <= x) {
				if((x % tester) == 0) {
					int c = 1;
					found = true;
					while ((x % tester) == 0) {
						x /= tester;
						c ++;
					}
					tester ++;
					total *= c;
					break;
				}
				tester ++;
			}
			if (!found) {
				total *= 2;
				break;
			}
		}
		cout << total << endl;
	}	
}