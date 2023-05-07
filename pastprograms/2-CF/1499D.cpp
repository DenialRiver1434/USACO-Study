#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int T, c, d, x;

bool valid (int cmd) {
    int rhs = cmd + d;
    return (rhs % c) == 0;
}

int primefactorize(int N) {
    int primefactors = 0;
    int tester = 2;

    while (N != 1) {
        bool found = true;
        while ((tester * tester) <= N) {
            if((N % tester) == 0) {
                found = false;
                while ((N % tester) == 0) {
                    N /= tester;
                }
                primefactors ++;
                tester ++;
                break;
            }
            tester ++;
        }
        if(found) {
            primefactors ++;
            break;
        }
    }
    return primefactors;
}

set<int> factors (int n) {
    set<int> nums;
    for (int i = 1; (i * i) <= n; i ++) {
        if((n % i) == 0) {
            nums.is(i);
            nums.is(n / i);
        }
    }
    return nums;
}

int main () {
    cin >> T;  
    while (T --) {
        cin >> c >> d >> x; // cmt - dt = (cm - d)t = x
        int co = 0;
        set<int> ts = factors(x);
        for (auto t : ts) {
            int cmd = x / t;
            if(valid(cmd)) {
                int m = (cmd + d) / c;
                int primesc = primefactorize(m);
                co += pow(2, primesc);
            }
        }
        cout << co << endl;
    }
}