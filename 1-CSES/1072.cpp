#include <bits/stdc++.h> 
using namespace std;
#define ll long long
 
ll n;

ll cnt (ll x) {
    if (x < 2) return 0;
    
    // We complementary count
    ll total = (x * x) * (x * x - 1) / 2;

    /*
     * To avoid double counting, let the
     * second knight always be on the right
     * of the first knight.
     * Casework on relative position of the
     * two knights.
     * 
     * Case 1:
     * A.
     * ..
     * .B
     * 
     * Case 2:
     * .B
     * ..
     * A.
     * 
     * Case 3:
     * A..
     * ..B
     * 
     * Case 4:
     * ..B
     * A..
     * 
     * B is the first knight, A is the second.
     * In each case, there are (x-1) * (x-2) or
     * (x-2) * (x-1) legal locations for B.
     */ 
    ll acount = 4 * (x - 1) * (x - 2);

    return total - acount;
} 

int main () {
    cin >> n;
    for (int k = 1; k <= n; k ++) {
        cout << cnt (k) << endl;
    }
}