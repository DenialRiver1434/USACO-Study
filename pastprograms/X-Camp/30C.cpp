#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int a, b, c, x, y, z;
bool searched[200][200][200];
queue<tuple<int, int, int, int>> remain; 

void possible (int aa, int bb, int cc, int d) {
    if(aa >= -100 && aa < 100 && bb >= -100 && bb < 100 && cc >= -100 && cc < 100) {
        if(searched[aa + 100][bb + 100][cc + 100]) return;
        searched[aa + 100][bb + 100][cc + 100] = true;
        remain.push(mt(aa, bb, cc, d));
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> a >> b >> c >> x >> y >> z;
    remain.push(mt(a, b, c, 0));
    while(remain.size()) {
        tuple<int, int, int, int> t = remain.front();
        remain.pop();
        int pa = get<0>(t), tb = get<1>(t), pc = get<2>(t), depth = get<3>(t);
        if(pa == x && tb == y && pc == z) {
            cout << "YES" << endl << depth;
            return 0;
        }
    }
}