#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int N, C = 0, counts[100002];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N; 
    counts[0] = -1; counts[N + 1] = -1;
    for (int i = 1; i <= N; i ++) {
        int a; cin >> a;
        C += a;
        counts[i] = a;
    }
    
    int pos = 1;
    bool dir = 1;
    for (int i = 0; i < C; i ++) {
        if(counts[pos - 1] < counts[pos]) {
            dir = 1;
            cout << "R";
            counts[pos] --;
            pos ++;
        }
        else if(counts[pos - 1] == counts[pos]) {
            if(dir == 1) {
                cout << "R";
                counts[pos] --;
                pos ++;
            }
            else {
                cout << "L";
                counts[pos - 1] --;
                pos --;
            }
        }
        else {
            dir = 0;
            cout << "L";
            counts[pos - 1] --;
            pos --;
        }
    }
}