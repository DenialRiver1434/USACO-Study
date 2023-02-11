#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

bitset<5000001> nprime;
set<int> onem4, twom4, threem4;

void sieve () {
    for (int i = 2; i < 5000001; i ++) {
        if(!nprime[i]) {
            if((i % 4) == 1) onem4.is(i);
            if((i % 4) == 2) twom4.is(i);
            if((i % 4) == 3) threem4.is(i);
            for (int j = 2 * i; j < 5000001; j += i) {
                nprime[j] = true;
            }
        }
    }
}

int test (int num) {
    if(num < 4) return 1;
    if((num % 4) == 0) return num / 2;
    if(!nprime[num]) return 1;

    if((num % 4) == 1) {
        auto itr = onem4.lower_bound(num);
        itr --;
        num -= *itr;
        return 1 + (num / 2);
    }
    else if((num % 4) == 2) {
        return num / 2;
    }
    else {
        auto itr = threem4.lower_bound(num);
        itr --;
        num -= *itr;
        return 1 + (num / 2);
    }
}

int main () {
    sieve();
    int T; cin >> T;
    ofstream fout; fout.open("temp.out");
    while (T --) {
        int N; cin >> N;
        int bestrot = 5e6 + 2; 

        for (int i = 0; i < N; i ++) {
            int a; cin >> a;
            if((test(a) / 2) < (bestrot / 2)) bestrot = min(bestrot, test(a));
        }

        if((bestrot % 2) == 1) {
            cout << "Farmer John" << endl;
        }
        else {
            cout << "Farmer Nhoj" << endl;
        }
    }
}