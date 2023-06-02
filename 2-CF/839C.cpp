#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector<int> conn[100000];

double ev (int a, int prev) {
    double total = 0;
    int of = 0;
    for (auto co : conn[a]) {
        if(co != prev) {
            of ++;
            total += ev(co, a);
        }
    }
    if(of) {
        return 1 + (total / of);
    }
    return 1;
}

int main() {
    cin >> N;
    for (int i = 1; i < N; i ++) {
        cin >> a >> b;
        conn[--a].pb(--b);
        conn[b].pb(a);
    }
    cout << setprecision(12) << ev(0, -1) - 1;
}