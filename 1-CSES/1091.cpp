#define pb push_back
#define mt make_tuple
#include <bits/stdc++.h>
using namespace std;

int N, M, a;
multiset<int> price;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        cin >> a;
        price.insert(a);
    }
    for (int i = 0; i < M; i ++) {
        cin >> a;
        auto loc = price.lower_bound(a);
        if(*loc == a) {
            cout << *loc << endl;
            price.erase(price.find(*loc));
        }
        else {
            if(loc == price.begin()) {
                cout << -1 << endl;
            }
            else {
                loc --;
                cout << *loc << endl;
                price.erase(price.find(*loc));
            }
        }
    }
}