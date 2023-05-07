#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int isin[1000001];

int main () {
    int N; cin >> N;
    while (N --) {
        int a; cin >> a;
        isin[a] ++;
    }
    
    for (int i = 1000000; i >= 2; i --) {
        int found = 0;
        for (int j = i; j < 1000001; j += i) {
            found += isin[j];
            if(found > 1) {
                cout << i;
                return 0;
            }
        }
    }
    cout << 1;
    return 0;
}