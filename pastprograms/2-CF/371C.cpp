#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll bb = 0, bs = 0, bc = 0, nb, ns, nc, prb, prs, prc, r, tr, made = 0, cost = 0;
string read;

void create () {
	if(nb >= bb) nb -= bb;
	else {
		r -= (bb - nb) * prb;
		nb = 0;
	}
	if(ns >= bs) ns -= bs;
	else {
		r -= (bs - ns) * prs;
		ns = 0;
	}
	if(nc >= bc) nc -= bc;
	else {
		r -= (bc - nc) * prc;
		nc = 0;
	}
}

int main() {
	cin >> read >> nb >> ns >> nc >> prb >> prs >> prc >> tr;
	for (auto r : read) {
		if(r == 'B') {
			bb ++;
			cost += prb;
		}
		else if(r == 'S') {
			bs ++;
			cost += prs;
		}
		else {
			bc ++;
			cost += prc;
		}
	}
	r = tr;
	ll c = 0;
	if (bb == 0) nb = 0;
	if (bs == 0) ns = 0;
	if (bc == 0) nc = 0;
	while ((nb > 0) || (ns > 0) || (nc > 0)) {
		create();
		if(r < 0) {
			cout << made;
			return 0;
		}
		made ++;
	}
	made += (r / cost);
	cout << made;
}