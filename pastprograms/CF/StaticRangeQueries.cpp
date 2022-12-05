#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll N, Q, a, b, c;
map<ll, ll> change, prefix;

ll getprefix(ll pos) {
	auto itr = prefix.lower_bound(pos);
	itr --;
	ll left = (*itr).first, right = (*(++ itr)).first;
	ll lval = prefix[left], rval = prefix[right];
	ll diffval = rval - lval, diffpos = right - left;
	ll ret = (diffval * (pos - left)) / diffpos;
	return ret + lval;
}

int main() {
	cin >> N >> Q;
	for (ll i = 0; i < N; i ++) {
		cin >> a >> b >> c;
		if(change.find(a) == change.end()) change[a] = c;
		else change[a] += c;
		if(change.find(b) == change.end()) change[b] = -c;
		else change[b] -= c;
	}
	prefix[-1] = 0;
	ll term = 0, prev = -1, psum = 0;
	for (auto ch : change) {
		int pos = ch.first, delta = ch.second;
		prefix[pos] = psum + term * (pos - prev);
		term += delta;
		prev = pos;
		psum = prefix[pos];
	}
	prefix[1000000001] = psum + term * (1000000001 - prev);
	for (ll i = 0; i < Q; i ++) {
		cin >> a >> b;
		cout << getprefix(b) - getprefix(a) << endl;
	}
}