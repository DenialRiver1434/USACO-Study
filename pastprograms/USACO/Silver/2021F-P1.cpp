#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, a, b, cur = 0;
bool filled[2010][2010];
queue<pair<int, int>> pending;

bool problem (pair<int, int> inp) {
    int c = 0;
    if(!filled[inp.first][inp.second]) return false;
    c += filled[inp.first - 1][inp.second];
    c += filled[inp.first][inp.second - 1]; 
    c += filled[inp.first + 1][inp.second];
    c += filled[inp.first][inp.second + 1]; 
    return (c == 3);
}

void add (int a, int b) {
    cur ++;
    filled[a][b] = true;
    pending.push(mp(a, b));
    pending.push(mp(a - 1, b));
    pending.push(mp(a + 1, b));
    pending.push(mp(a, b - 1));
    pending.push(mp(a, b + 1));
}

pair<int, int> missing (int a, int b) {
    filled[a][b] = true;
    if(!filled[a - 1][b]) return mp(a - 1, b);
    if(!filled[a + 1][b]) return mp(a + 1, b);
    if(!filled[a][b - 1]) return mp(a, b - 1);
    else return mp(a, b + 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> a >> b;
        a += 502; b += 502;

        cur --;
        if(filled[a][b]) cur --;
        else filled[a][b] = true;
        add(a, b);
        filled[a][b] = true;
        while(pending.size()) {
            auto pair = pending.front();
            pending.pop();
            if(problem(pair)) {
                auto tup = missing(pair.first, pair.second);
                add(tup.first, tup.second);
            }
        }
        cout << cur << endl;
    }
}