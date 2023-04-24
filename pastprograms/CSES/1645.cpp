#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (lll i = begin; i < n; i ++)
#define len(x) x.size()
#define vi vector<int>
#define vpi vector<pair<int, int>>
#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> s;

int main() {
    lll N; cin >> N;
    s.push({0, 0});
    f0r (i, 1, N + 1) {
        lll a; cin >> a;
        while(s.top().second >= a) s.pop();
        cout << s.top().first << " ";
        s.push({i, a});
    }
}
