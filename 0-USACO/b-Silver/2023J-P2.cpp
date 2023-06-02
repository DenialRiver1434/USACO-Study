#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int N, Q, weight[1500][1500];
bool dir[1500][1500]; // right = 1, down = 0
int rresult[1500], dresult[1500];

void calculate () {
    int initial = 0;
    for (int i = 0; i < N; i ++) {
        if(dir[i][N - 1]) initial += (weight[i][N - 1] * rresult[i]);
    }
    for (int i = 0; i < N; i ++) {
        if(!dir[N - 1][i]) initial += (weight[N - 1][i] * dresult[i]);
    }
    cout << initial << '\n';
}

void path (int x, int y, int ch) {
    if(x >= N || y >= N) return;
    weight[x][y] += ch;
    if(!dir[x][y]) path(x + 1, y, ch);
    else path(x, y + 1, ch);
}

void change () {
    int x, y;
    cin >> x >> y;
    x --; y --;
    if(dir[x][y]) {
        dir[x][y] = false;
        path (x, y + 1, -weight[x][y]);
        path (x + 1, y, weight[x][y]);
    }
    else {
        dir[x][y] = true;
        path (x, y + 1, weight[x][y]);
        path (x + 1, y, -weight[x][y]);
    }
    calculate();
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            char d; cin >> d;
            dir[i][j] = (d == 'R');
        }
        int cost; cin >> cost;
        rresult[i] = cost;
    }
    for (int i = 0; i < N; i ++) {
        int cost; cin >> cost; 
        dresult[i] = cost;
    }

    int initial = 0;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            weight[i][j] = 1;
            if(i > 0) {
                if(!dir[i - 1][j]) {
                    weight[i][j] += weight[i - 1][j];
                }
            }
            if(j > 0) {
                if(dir[i][j - 1]) {
                    weight[i][j] += weight[i][j - 1];
                }
            }
            cout << weight[i][j] << ' ';
        }
        cout << '\n';
    }

    calculate();
    
    cin >> Q;
    while (Q --) {
        change();
    }
}