#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll K, M, N, a, b, total = 0;
map<ll, ll> positions, prefpos;
vector<ll> nums, pos;
multiset<ll> adds;

ll findrangesum (double left, double right) {
    ll lhs = lower_bound(pos.begin(), pos.end(), left) - pos.begin(), rhs = lower_bound(pos.begin(), pos.end(), right) - pos.begin();
    if(lhs == rhs) return 0;
    if(rhs == K) {
        return total - prefpos[pos[lhs]];
    }
    return prefpos[pos[rhs]] - prefpos[pos[lhs]];
}

int main() {
    cin >> K >> M >> N;
    for (ll i = 0; i < K; i ++) {
        cin >> a >> b;
        positions[a] = b;
    }
    nums.pb(-1e10);
    for (ll i = 0; i < M; i ++) {
        cin >> a;
        if(positions.find(a) != positions.end()) positions.erase(a);
        nums.pb(a);
    }
    nums.pb(1e10);
    ll c = 0, prev = 0;
    for (auto p : positions) {
        pos.pb(p.first);
        c += p.second;
        prefpos[p.first] = prev;
        prev = c;
        total += p.second;
    }
    sort(nums.begin(), nums.end());
    for (ll i = 0; i < M + 1; i ++) { // iterating nums
        double left = nums[i], right = nums[i + 1];
        ll twomax = findrangesum(left, right);
        ll onemax = 0;
        double dif = (right - left) / 2;
        ll lhs = lower_bound(pos.begin(), pos.end(), left) - pos.begin(), rhs = lower_bound(pos.begin(), pos.end(), right) - pos.begin();
        for (ll i = lhs; i < rhs; i ++) {
            double l = pos[i] - 1e-10;
            double r = min(right, l + dif);
            onemax = max(onemax, findrangesum(l, r));
        }
        adds.is(onemax);
        adds.is(twomax - onemax);
    }
    ll total = 0;
    for (ll i = 0; i < N; i ++) {
        if(!adds.empty()) {
            ll top = *adds.rbegin();
            total += top;
            adds.erase(adds.find(top));
        }
    }
    cout << total;
}