#define pb push_back
#define mt make_tuple
#define is insert
#include <bits/stdc++.h>
using namespace std;

long long N, M, a;
multiset<long long> lengths;

int main() {
    cin >> N >> M;
    for (long long i = 0; i < M; i ++) {
        cin >> a;
        lengths.is(a);
    }
    long long c = 0, f, s;
    while(lengths.size() > 1) {
        f = *lengths.begin();
        lengths.erase(lengths.find(f));
        s = *lengths.begin();
        lengths.erase(lengths.find(s));
        c += (f + s);
        lengths.is(f + s);
    }
    cout << c;
}