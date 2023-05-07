#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, a, b, co = 0;
char cha;
vector<int> conn[100000];
set<int> powers = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};

void ts (int a, int prev) {
    int needed = 1;
    for (auto c : conn[a]) {
        if (c != prev) {
            needed ++;
            co ++;
            ts (c, a);
        }
    }
    if(powers.find(needed) != powers.end()) co += round(log2(needed));
    else co += ceil(log2(needed));
}

int main() {
    cin >> N;
    for (int i = 1; i < N; i ++) {
        cin >> a >> b;
        conn[--a].pb(--b);
        conn[b].pb(a);
    }
    ts(0, -1);
    cout << co;
}