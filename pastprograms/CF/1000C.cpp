#define pb push_back
#define mt make_tuple
#define is insert
#include <bits/stdc++.h>
using namespace std;

long long N, a, b;
map<long long, long long> changes;
set<long long> points;
long long counts[200001];

int main() {
    cin >> N;
    for (long long i = 0; i < N; i ++) {
        cin >> a >> b;
        if(changes.find(a) == changes.end()) changes[a] = 1;
        else changes[a] ++;
        if(changes.find(b + 1) == changes.end()) changes[b + 1] = -1;
        else changes[b + 1] --;
        points.insert(a);
        points.insert(b + 1);
    }

    long long prevloc = *points.begin();
    long long prevcover = 0;
    for (auto p : points) {
        counts[prevcover] += (p - prevloc);
        prevloc = p;
        prevcover += changes[p];
    }
    for (long long i = 1; i <= N; i ++) {
        cout << counts[i] << " ";
    }
}