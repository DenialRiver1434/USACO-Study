#define pb push_back
#define mt make_tuple
#define is insert
#include <bits/stdc++.h>
using namespace std;

bool cmp(tuple<int, int> a, tuple<int, int> b) {
    if(get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
    return get<1>(a) < get<1>(b);
}

int N, M, a, b, c = 0;
multiset<tuple<int, int>, decltype(cmp)*> backsort(cmp);
multiset<int> finishes;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        cin >> a >> b;
        backsort.is(mt(a, b));    
    }
    for (int i = 0; i < M; i ++) finishes.is(0);

    for (auto b : backsort) {
        int start = get<0>(b), finish = get<1>(b);
        auto it = finishes.upper_bound(start);
		if (it == begin(finishes)) continue;
		finishes.erase(--it);
		finishes.is(finish);
		c ++;
    }
    cout << c;
}