/*
ID: shurong1
LANG: C++
TASK: sort3
*/

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N;

int main () {
    ifstream fin; fin.open("sort3.in");
    ofstream fout; fout.open("sort3.out");
    fin >> N;

    vector<int> order;
    int c1 = 0, c2 = 0, c3 = 0, t = 0;
    for (int i = 0; i < N; i ++) {
        int a; fin >> a;
        if(a == 1) c1 ++;
        if(a == 2) c2 ++;
        if(a == 3) c3 ++;
        order.pb(a);
    }
    int c12 = 0, c13 = 0, c21 = 0, c23 = 0, c31 = 0, c32 = 0;
    for (int i = 0; i < c1; i ++) {
        if(order[i] == 2) c12 ++;
        if(order[i] == 3) c13 ++;
    }
    for (int i = c1; i < (c1 + c2); i ++) {
        if(order[i] == 1) c21 ++;
        if(order[i] == 3) c23 ++;
    }
    for (int i = (c1 + c2); i < (c1 + c2 + c3); i ++) {
        if(order[i] == 2) c32 ++;
        if(order[i] == 1) c31 ++;
    }

    int p = min(c12, c21);
    c12 -= p; c21 -= p; t += p;
    p = min(c13, c31);
    c13 -= p; c31 -= p; t += p;
    p = min(c23, c32);
    c23 -= p; c32 -= p; t += p;
/*
    cout << "* " << c12 << " " << c13 << endl;
    cout << c21 << " * " << c23 << endl;
    cout << c31 << " " << c32 << " *" << endl;
*/
    t += max(c12, c21) * 2;
    fout << t << endl;
}
