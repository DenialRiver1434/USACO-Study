#define pb push_back
#include <bits/stdc++.h>
using namespace std;

int N;
string inp;
vector<string> lstrings;

bool abetterb (string a, string b) {
    return (a + b) < (b + a);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> inp;
        lstrings.pb(inp);
    }
    sort(lstrings.begin(), lstrings.end(), abetterb);
    for (auto l : lstrings) cout << l;
}