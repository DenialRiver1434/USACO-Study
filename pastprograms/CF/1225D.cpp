#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

map<set<pair<int, int>>, int> past;

map<int, int> primefactorize(int N) {
    map<int, int> primefactors;
    int tester = 2, c;
    while (N != 1) {
        c = 0;
        while ((tester * tester) <= N) {
            if((N % tester) == 0) {
                c = 0;
                while ((N % tester) == 0) {
                    N /= tester;
                    c ++;
                }
                primefactors[tester ++] = c;
                break;
            }
            tester ++;
        }
        if (!c) {
            primefactors[N] = 1;
            break;
        }
    }
    return primefactors;
}

int main () {
    int N, K;
    cin >> N >> K;
    ll c = 0, trueempty = 0;
    for (int i = 0; i < N; i ++) {
        int a;
        cin >> a;
        map<int, int> factorization = primefactorize(a);
        vector<pair<int, int>> filtered;
        for (auto f : factorization) {
            if((f.second % K) != 0) filtered.pb(mp(f.first, f.second % K));
        }
        if (filtered.empty()) {
            c += trueempty ++;
            continue;
        }

        set<pair<int, int>> need, have;
        for (auto f : filtered) {
            int prime = f.first, power = f.second % K, needs = (K - f.second) % K;
            need.is(mp(prime, needs));
            have.is(mp(prime, power));
        }
        c += (past[need]);
        past[have] ++;
    }
    cout << c;
}