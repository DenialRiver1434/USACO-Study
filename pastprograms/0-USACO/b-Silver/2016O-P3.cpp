#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
map<int, set<int>> connections;
set<int> open;
bool hit[3001];

void dfs(int pos) {
	hit[pos] = true;
	for (auto c : connections[pos]) {
		if(!hit[c]) dfs(c);
	}
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("closing.in");
	fout.open("closing.out");


	fin >> N >> M;
	for (int i = 0; i < M; i ++) {
		fin >> a >> b;
		if(connections.find(a) == connections.end()) connections[a] = {b};
		else connections[a].is(b);
		if(connections.find(b) == connections.end()) connections[b] = {a};
		else connections[b].is(a);
	}
	for (int i = 1; i <= N; i ++) open.is(i);

	dfs(1);
	bool found = true;
	for (auto o : open) {
		if(!hit[o]) found = false;
	}
	if(found)  fout << "YES" << endl;
	else fout << "NO" << endl;
	for (int i = 1; i < N; i ++) {
		found = true;
		fin >> a;
		open.erase(a);
		set<int> affected = connections[a];
		for (auto af : affected) connections[af].erase(a);
		connections.erase(a);

		for (int j = 1; j <= N; j ++) hit[j] = false;
		dfs(*open.begin());
		for (auto o : open) {
			if(!hit[o]) found = false;
		}
		if(found)  fout << "YES" << endl;
		else fout << "NO" << endl;
	}
}