#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> evens; multiset<int> nums; 
    int c1 = 0; 
    for_loop (i, 0, N) {
        int a; cin >> a;
        nums.is(a);
        if(a == 1) c1 ++;
        if((a % 2) == 0) evens.pb(a);
    }
    sort(evens.begin(), evens.end());

    int es = evens.size();
    for_loop (i, 0, min(c1, es)) {
        nums.erase(nums.find(evens[i]));
        nums.is(evens[i] + 1);
    }
    ll op = 1;
    for (auto n : nums) {
        op = (op * n) % 1000000007;
    }
    cout << op;
}