#define pb push_back
#define mp make_pair
#define mt make_tuples
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int N, a;

int main() {
    while (true) {
        cout << "next 0" << endl;
        cout.flush();
        cin >> N;
        for (int i = 0; i < N; i ++) cin >> a;
        cout << "next 0 1" << endl;
        cout.flush();
        cin >> N;
        for (int i = 0; i < N; i ++) cin >> a;
        if(N == 2) break;
    }
    while (true) {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        cout.flush();
        cin >> N;
        for (int i = 0; i < N; i ++) cin >> a;
        if(N == 1) break;
    }
    cout << "done" << endl;
}