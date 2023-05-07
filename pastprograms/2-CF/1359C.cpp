#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll T, a, b, c;

int main() {
    cin >> T;
    while (T --) {
        cin >> a >> b >> c;
        if(((a + b) / 2) >= c) {
            cout << 2 << endl;
            continue; // avoids div by 0
        }
        ll testa = (c - a) / (a + b - 2*c); // 2, 3
        ll testb = testa + 1;
        ll adjusteda = (a * (testa + 1) + b * testa) * (2 * testb + 1);
        ll adjustedb = (a * (testb + 1) + b * testb) * (2 * testa + 1);
        ll target = c * (2 * testb + 1) * (2 * testa + 1);
        if(abs(adjusteda - target) > abs(adjustedb - target)) {
            cout << 2 * testb + 1 << endl;
        }
        else {
            cout << 2 * testa + 1 << endl;
        }
    }
}
