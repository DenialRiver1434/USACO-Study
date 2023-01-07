#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

ll result (ll a, ll b) {
    if (b == 0) return 1;
    else if ((b % 2) == 1) return (((result (a, b / 2) * result (a, b / 2)) % 1000000007) * a) % 1000000007;
    else return (result (a, b / 2) * result (a, b / 2)) % 1000000007;
}

int main () {
    int T; cin >> T;  
    while (T --) {
        ll a, b;
        cin >> a >> b;
        cout << result(a % (1000000007), b) << endl;
    }
}