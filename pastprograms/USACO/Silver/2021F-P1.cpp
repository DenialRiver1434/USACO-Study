#include <bits/stdc++.h>
using namespace std;

map<int, set<tuple<int, int>>> listofn;
map<tuple<int, int>, int> numadjacent;
set<tuple<int, int>> added;
int N, a, b, addedlen = 0;

int countadjacent (tuple<int, int> x) {
	int c = 0;
	int a = get<0>(x), b = get<1>(x);
	if(added.find(make_tuple(a + 1, b)) != added.end()) c ++;
	if(added.find(make_tuple(a - 1, b)) != added.end()) c ++;
	if(added.find(make_tuple(a, b + 1)) != added.end()) c ++;
	if(added.find(make_tuple(a, b - 1)) != added.end()) c ++;
	return c;
}

void add (tuple<int, int> x) {
	int a = get<0>(x), b = get<1>(x);
	if(added.find(x) == added.end()){
		added.insert(x);
		addedlen ++;
		int adj = countadjacent(x);
		numadjacent[x] = adj;
		listofn[adj].insert(x);
		tuple<int, int> temp = make_tuple(a + 1, b);
		if(added.find(temp) != added.end()) {
			listofn[numadjacent[temp]].erase(temp);
			int a = countadjacent(temp);
			numadjacent[temp] = a;
			listofn[a].insert(temp);
		}
		temp = make_tuple(a - 1, b);
		if(added.find(make_tuple(a - 1, b)) != added.end()) {
			listofn[numadjacent[temp]].erase(temp);
			int a = countadjacent(temp);
			numadjacent[temp] = a;
			listofn[a].insert(temp);
		}
		temp = make_tuple(a, b + 1);
		if(added.find(make_tuple(a, b + 1)) != added.end()) {
			listofn[numadjacent[temp]].erase(temp);
			int a = countadjacent(temp);
			numadjacent[temp] = a;
			listofn[a].insert(temp);
		}
		temp = make_tuple(a, b - 1);
		if(added.find(make_tuple(a, b - 1)) != added.end()) {
			listofn[numadjacent[temp]].erase(temp);
			int a = countadjacent(temp);
			numadjacent[temp] = a;
			listofn[a].insert(temp);
		}
	}
}

tuple<int, int> checkmissing (tuple<int, int> x) {
	int a = get<0>(x), b = get<1>(x);
	if(added.find(make_tuple(a + 1, b)) == added.end()) return make_tuple(a + 1, b);
	if(added.find(make_tuple(a - 1, b)) == added.end()) return make_tuple(a - 1, b);
	if(added.find(make_tuple(a, b + 1)) == added.end()) return make_tuple(a, b + 1);
	if(added.find(make_tuple(a, b - 1)) == added.end()) return make_tuple(a, b - 1);
	else throw invalid_argument("No adjacencies");
}

int main () {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> a >> b;
		add(make_tuple(a, b));
		while(!listofn[3].empty()) {
			auto count = listofn[3].begin();
			tuple<int, int> victim = *count;
			tuple<int, int> missing = checkmissing(victim);
			add(missing);
		}
		cout << addedlen - i - 1 << endl;
	}
}