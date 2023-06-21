#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> inps;

bool comp (string a, string b) {
    return (a + b) < (b + a);
}

int main() {
    cin >> n;
    // Reading input to inps
    for (int i = 0; i < n; i ++) {
        string inp; cin >> inp;
        inps.push_back(inp);
    }

    // Sorting by custom comparator
    sort(inps.begin(), inps.end(), comp);

    // Printing it all back out in the lexicographically smallest order
    for (auto l : inps) {
        cout << l;
    }
}