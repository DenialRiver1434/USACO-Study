#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int colors[100001];
map<int, vector<int>> connections;
int N, M, a, b;
void flood(int pos, int color) {
	if(colors[pos] != -1) return;
	vector<int> con = connections[pos];
	colors[pos] = color;
	for (auto c : con) {
		flood(c, color);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i ++) {
		cin >> a >> b;
		a --; b --;
		if(connections.find(a) == connections.end()) connections[a] = {b};
		else connections[a].pb(b);
		if(connections.find(b) == connections.end()) connections[b] = {a};
		else connections[b].pb(a);
	}
	for (int i = 0; i < N; i ++) colors[i] = (-1);
	vector<int> starts;
	int col = 0;
	for (int i = 0; i < N; i ++) {
		if(colors[i] == -1) {
			col ++;
			starts.pb(i);
			flood(i, col);
		}
	} 
	cout << col - 1 << endl;
	for (int i = 0; i < (col - 1); i ++) {
		cout << starts[i] + 1 << " " << starts[i + 1] + 1 << endl;
	}
}