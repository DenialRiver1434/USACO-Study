#define pb push_back
#define mt make_tuple
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll N, a, b;
vector<tuple<ll, ll>> coords;
map<ll, vector<ll>> xs, ys;
map<tuple<ll, ll>, ll> xsum, ysum; // First ll is the x, second ll is the y

int main () {
    ifstream fin;
    fin.open("triangles.in");
    ofstream fout;
    fout.open("triangles.out");

    fin >> N;
    for (ll i = 0; i < N; i ++) {
        fin >> a >> b;
        coords.pb(mt(a, b));
        if(xs.find(a) == xs.end()) xs[a] = {b};
        else xs[a].pb(b);
        if(ys.find(b) == ys.end()) ys[b] = {a};
        else ys[b].pb(a);
    }
    for (auto pair : xs) {
        sort(xs[get<0>(pair)].begin(), xs[get<0>(pair)].end());
        vector<ll> nums = xs[get<0>(pair)];
        ll baseline = 0, start = nums[0];
        for (auto n : nums) baseline += abs(n - start); // nums[i] is y-coord, get<0>(pair) is x-coord
        xsum[mt(get<0>(pair), nums[0])] = baseline;
        ll n = nums.size();
        for (ll i = 1; i < n; i ++) {
            baseline += (2 * i - n) * (nums[i] - nums[i - 1]);
            xsum[mt(get<0>(pair), nums[i])] = baseline;
        }
    }
    for (auto pair : ys) {
        sort(ys[get<0>(pair)].begin(), ys[get<0>(pair)].end());
        vector<ll> nums = ys[get<0>(pair)];
        ll baseline = 0, start = nums[0];
        for (auto n : nums) baseline += abs(n - start); // nums[i] is x-coord, get<0>(pair) is y-coord
        ysum[mt(nums[0], get<0>(pair))] = baseline;
        ll n = nums.size();
        for (ll i = 1; i < n; i ++) {
            baseline += (2 * i - n) * (nums[i] - nums[i - 1]);
            ysum[mt(nums[i], get<0>(pair))] = baseline;
        }
    }
    ll c = 0;
    for (auto pair : coords) {
        c += xsum[pair] * ysum[pair];
    }
    fout << (c % (1000000007));
}