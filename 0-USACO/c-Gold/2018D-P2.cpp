#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;


int main () {
    ifstream fin; fin.open("cowpatibility.in");
    ofstream fout; fout.open("cowpatibility.out");

    ll N; fin >> N;
    map<ll, ll> count1;
    map<pair<ll, ll>, ll> count2;
    map<tuple<ll, ll, ll>, ll> count3;
    map<tuple<ll, ll, ll, ll>, ll> count4;
    map<tuple<ll, ll, ll, ll, ll>, ll> count5;

    ll co = 0;
    for (ll i = 0; i < N; i ++) {
        ll tbs[5];
        for_loop (i, 0, 5) fin >> tbs[i];
        sort(tbs, tbs+5);
        ll a = tbs[0], b = tbs[1], c = tbs[2], d = tbs[3], e = tbs[4];

        // Single (5)
        co += count1[a]; co += count1[b]; co += count1[c]; co += count1[d]; co += count1[e];
        count1[a] ++; count1[b] ++; count1[c] ++; count1[d] ++; count1[e] ++;

        // Double (10)
        co -= count2[mp(a, b)]; co -= count2[mp(a, c)]; co -= count2[mp(a, d)]; co -= count2[mp(a, e)];
        co -= count2[mp(b, c)]; co -= count2[mp(b, d)]; co -= count2[mp(b, e)];
        co -= count2[mp(c, d)]; co -= count2[mp(c, e)];
        co -= count2[mp(d, e)];
        count2[mp(a, b)] ++; count2[mp(a, c)] ++; count2[mp(a, d)] ++; count2[mp(a, e)] ++; 
        count2[mp(b, c)] ++; count2[mp(b, d)] ++; count2[mp(b, e)] ++; 
        count2[mp(c, d)] ++; count2[mp(c, e)] ++;
        count2[mp(d, e)] ++;

        // Triple (10)
        co += (count3[mt(a, b, c)] ++); co += (count3[mt(a, b, d)] ++); co += (count3[mt(a, b, e)] ++); co += (count3[mt(a, c, d)] ++); co += (count3[mt(a, c, e)] ++); co += (count3[mt(a, d, e)] ++);
        co += (count3[mt(b, c, d)] ++); co += (count3[mt(b, c, e)] ++); co += (count3[mt(b, d, e)] ++); 
        co += (count3[mt(c, d, e)] ++);

        // Quad (5)
        co -= (count4[mt(a, b, c, d)] ++); co -= (count4[mt(a, b, c, e)] ++); co -= (count4[mt(a, b, d, e)] ++); co -= (count4[mt(a, c, d, e)] ++); co -= (count4[mt(b, c, d, e)] ++);

        // Quntiuplet (1)
        co += (count5[mt(a, b, c, d, e)] ++);
    }
    fout << ((N * (N - 1)) / 2) - co;
}