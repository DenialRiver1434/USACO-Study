#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll sumto (ll n) {
    return (((n % (1000000007)) * ((n % (1000000007)) + 1)) / 2) % (1000000007);
}

int main () {
    ll N, count = 0, searched = 1e12; cin >> N;
    for (ll i = 1; (i * i) <= N; i ++) {
        searched = min(searched, N / i);
        count = (count + sumto(N / i)) % 1000000007;
    }
    for (ll i = 1; i < searched; i ++) { // count number with this many terms
        ll right = N / i, left = N / (i + 1);
        count = (count + (right - left) * sumto(i)) % 1000000007;
    }
    cout << count;
}