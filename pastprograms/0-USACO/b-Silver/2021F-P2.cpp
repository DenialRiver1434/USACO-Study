#include <bits/stdc++.h>
using namespace std;

vector<int> years;
vector<int> diff;
int N, M, a;

int main () {
	cin >> N >> M;
	int baseline = 0;
	for (int i = 0; i < N; i ++) {
		cin >> a;
		int back = a / 12;
		years.push_back(back + 1);
		baseline = max(baseline, back + 1);
	}
	sort(years.begin(), years.end());
	int prev = 0, df = 0;
	for (int y : years) {
		if((y - prev) > 1) {
			diff.push_back(y - prev - 1);
			df ++;
		}
		prev = y;
	}
	M = min(df, M - 1);
	sort(diff.begin(), diff.end(), greater<int>());
	for (int i = 0; i < M; i ++) baseline -= diff[i];
	cout << baseline * 12;
}