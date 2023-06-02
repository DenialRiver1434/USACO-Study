#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll N;

int main () {
    cin >> N;
    map<ll, ll> primefactors;
    ll tester = 2, c;
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
    ll total = 0;
    for (auto p : primefactors) {
        double adj = sqrt(2 * p.second + 0.25) - 0.5;
        ll test = floor(adj);
        if (((test * (test + 1))/ 2) > p.second) total += (test - 1);
        else total += test;
    }
    cout << total << endl;
}