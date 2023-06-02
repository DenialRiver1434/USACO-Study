#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

pair<int, int> ggcd (int a, int b) {
    if (a == 0) return mp(0, 1);
    if (b == 0) return mp(1, 0);
    int div = gcd(a, b);
    return mp(a / div, b / div);
}

int main () {
    int T;
    cin >> T;
    while (T --) {
        int N, c = 0; string inp;
        cin >> N; cin >> inp;
        map<pair<int, int>, int> counts;
        int a = 0, b = 0;
        for (auto ch : inp) {
            if(ch == 'D') a ++;
            else b ++;
            auto ret = ggcd(a, b);
            cout << (++counts[ret]) << " ";
        }
        cout << endl;
    }
}