#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

// WORK IN PROGRESS

map<string, int> decoder;
vector<int> conn[60];
int press[60];
int best[60][60][30][200]; // pos, time
bool done[25];

int main () {
	ifstream fin; fin.open("meetings.in");

	int N, start;
	fin >> N;
	for (int i = 0; i < N; i ++) {
		string a;
		fin >> a;
		if(a == "AA") start = i;
		decoder[a] = i;
	}	
	for (int i = 0; i < N; i ++) {
		string a; int b, c;
		fin >> a >> b >> c;
		int actual = decoder[a];
		press[actual] = b;
		for (int j = 0; j < c; j ++) {
			string d;
			fin >> d;
			conn[actual].pb(decoder[d]);
		}
		for (int z = 0; z < N; z ++) {
			for (int j = 0; j < 30; j ++) {
				for (int k = 0; k < 200; k ++) {
					best[i][z][j][k] = -1;
				}
			}
		}
	}
	queue<tuple<int, int, int, int, int, set<int>>> q; // pos, time, flowed, pressure, opened
	set<int> st;
	q.push(mt(start, start, 0, 0, 0, st));
	while (q.size()) {
		int posa = get<0>(q.front()), posb = get<1>(q.front()), time = get<2>(q.front()), flowed = get<3>(q.front()), pressure = get<4>(q.front());
		set<int> opened = get<5>(q.front());
		
		if(!done[time]) {
			done[time] = true;
			cout << time << endl;
		}

		q.pop();
		if(time == 25) {
			best[posa][posb][25][pressure] = max(best[posa][posb][25][pressure], flowed + pressure);
			continue;
		}
		if(best[posa][posb][time][pressure] >= flowed) continue;
		best[posa][posb][time][pressure] = flowed;


		flowed += pressure; time ++;
		if((press[posa] && opened.find(posa) == opened.end()) && (press[posb] && opened.find(posb) == opened.end()) && (posa != posb)) {
			opened.is(posa);
			opened.is(posb);
			q.push(mt(posa, posb, time, flowed, pressure + press[posa] + press[posb], opened));
			opened.erase(posa);
			opened.erase(posb);
		}
		if(press[posa] && opened.find(posa) == opened.end()) {
			opened.is(posa);
			for (auto c : conn[posb]) {
				q.push(mt(posa, c, time, flowed, pressure + press[posa], opened));
			}
			opened.erase(posa);
		}
		if(press[posb] && opened.find(posb) == opened.end()) {
			opened.is(posb);
			for (auto c : conn[posa]) {
				q.push(mt(c, posb, time, flowed, pressure + press[posb], opened));
			}
			opened.erase(posb);
		}
		for (auto ca : conn[posa]) {
			for (auto cb : conn[posb]) {
				q.push(mt(ca, cb, time, flowed, pressure, opened));
			}
		}
	}
	int bes = 0;
	for (int i = 0; i < 60; i ++) {
		for (int k = 0; k < 60; k ++) {
			for (int j = 0; j < 200; j ++) {
				bes = max(bes, best[i][k][25][j]);
			}
		}
	}
	cout << bes;
}