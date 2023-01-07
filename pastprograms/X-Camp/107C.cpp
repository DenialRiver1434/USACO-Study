#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int N, Q;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N >> Q;
    
    set<int> nums; multiset<int> dists;
    for (int i = 0; i < N; i ++) {
        int a; 
        cin >> a;
        nums.is(a);
    }
    for (auto itr = nums.begin(); itr != nums.end(); itr ++) {
        if(itr == nums.begin()) continue;
        auto nex = prev(itr);
        dists.is(*itr - *nex);
    }
    
    if(dists.empty()) cout << 0 << endl;
    else cout << (*nums.rbegin() - *nums.begin()) - *dists.rbegin() << endl;

    for_loop (i, 0, Q) {
        int a, b;
        cin >> a >> b;
        for_loop (j, 0, 1) { // Repeated never, just so that the continues can work
            if (a) {
                if(nums.find(b) != nums.end()) continue;
                if(b < *nums.begin()) {
                    dists.is(*nums.begin() - b);
                    nums.is(b);
                    continue;
                }
                if(b > *nums.rbegin()) {
                    dists.is(b - *nums.rbegin());
                    nums.is(b);
                    continue;
                }
                auto right = nums.lower_bound(b);
                auto left = prev(right);
                dists.erase(dists.find(*right - *left));
                dists.is(b - *left);
                dists.is(*right - b);
                nums.is(b);
            }
            else {
                if(nums.find(b) == nums.end()) continue;
                auto loc = nums.lower_bound(b);
                if(loc == nums.begin() && b == *nums.rbegin()) {
                    nums.erase(b);
                    continue;
                }
                if(loc == nums.begin()) {
                    auto right = next(loc);
                    dists.erase(dists.find(*right - *loc));
                    nums.erase(b);
                    continue;
                }
                if(b == *nums.rbegin()) {
                    auto left = prev(loc);
                    dists.erase(dists.find(*loc - *left));
                    nums.erase(b);
                    continue;
                }
                auto left = prev(loc);
                auto right = next(loc);
                dists.erase(dists.find(*right - *loc));
                dists.erase(dists.find(*loc - *left));
                dists.is(*right - *left);
                nums.erase(b);
            }
        }
        if(dists.empty()) cout << 0 << endl;
        else cout << (*nums.rbegin() - *nums.begin()) - *dists.rbegin() << endl;
    }
}