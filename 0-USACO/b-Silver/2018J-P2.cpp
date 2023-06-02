#define pb push_back
#define mp make_pair
#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<long long, long long>> vpi;
long long N, M, R, a, b, c = 0, bc;
vector<long long> milkp, rents;
vpi buying;

bool ycomp(pair<long long, long long> p, pair<long long, long long> q) { return p.second < q.second; }

long long remove(long long num) {
	long long c = 0;
	while(num != 0 && !buying.empty()) {
		long long avaliable = buying.back().first, cost = buying.back().second;
		if(avaliable <= num) { // go to next buyer
			num -= avaliable;
			c += cost * avaliable;
			buying.pop_back();
		}
		else {
			buying.back().first -= num;
			c += num * cost;
			num = 0;
		}
	}
	return c;
}

int main() {
    ifstream fin;
    fin.open("rental.in");
    ofstream fout;
    fout.open("rental.out");
	
	fin >> N >> M >> R;
	for (long long i = 0; i < N; i ++) { 
		fin >> a;
		milkp.pb(a);
	}
	sort(milkp.begin(), milkp.end(), greater<long long>());
	for (long long i = 0; i < M; i ++) { 
		fin >> a >> b;
		buying.pb(mp(a, b));
	}
	sort(buying.begin(), buying.end(), ycomp);
	for (long long i = 0; i < N; i ++) { 
		if(i < R) {
			fin >> a;
			rents.pb(a);
			c += a;
		}
		else rents.pb(0);
	}
	bc = c;
	sort(rents.begin(), rents.end(), greater<long long>());
	for (long long i = 0; i < N; i ++) {
		c -= rents.back();
		rents.pop_back();
		c += remove(milkp[i]);
		bc = max(bc, c);
	}
	fout << bc;
}