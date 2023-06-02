#define pb push_back
#define mp make_pair
#define mt make_tuples
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int N, a, pointto[1000];
bool visited[1000], incycle[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> a;
        pointto[i] = a - 1;
    }
    int pos = 0;
    while (true) {
        if(visited[pos]) {
            break;
        }
        visited[pos] = true;
        pos = pointto[pos];
    }
    while (true) {
        if(incycle[pos]) {
            break;
        }
        incycle[pos] = true;
        pos = pointto[pos];
    }
    for (int i = 0; i < N; i ++) {
        if (incycle[i]) cout << i + 1 << " ";
        else cout << pos + 1 << " ";
    }
}