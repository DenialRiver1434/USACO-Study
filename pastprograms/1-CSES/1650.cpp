#include <bits/stdc++.h>
using namespace std;

int N, Q, arr[200001], prefix[200001], a, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	prefix[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		prefix[i] = prefix[i - 1] ^ arr[i];
	}

	while (Q --) {
		cin >> a >> b;
		cout << (prefix[a - 1] ^ prefix[b]) << endl;
	}
}