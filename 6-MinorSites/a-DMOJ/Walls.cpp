#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include "bits/stdc++.h"
using namespace std;

int dist[30][200], N, M, L, common[250][250];
vector<int> club; 
set<int> regconn[200], pointconn[250];

int main () {
    cin >> M >> N >> L;
    f0r (i, 0, L) {
        int a; cin >> a;
        club.pb(a - 1);
    }
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            common[i][j] = -1;
        }
    }
    f0r (i, 0, M) {
        f0r (j, 0, L) {
            dist[j][i] = 1000000000;
        }
        int I, a, first; 
        cin >> I >> a; a --;
        first = a;

        pointconn[a].is(i);
        f0r (j, 1, I) {
            int b;
            cin >> b; b --;
            pointconn[b].is(i);
            if(common[a][b] != -1) {
                regconn[common[a][b]].is(i);
                regconn[i].is(common[a][b]);
            }
            else {
                common[b][a] = i;
            }
            a = b;
        }
        pointconn[first].is(i);
        if(common[a][first] != -1) {
            regconn[common[a][first]].is(i);
            regconn[i].is(common[a][first]);
        }
        else {
            common[first][a] = i;
        }
        a = first;
    }
    
    f0r (i, 0, L) {
        int member = club[i];
        queue<int> q;
        for (auto r : pointconn[member]) {
            dist[i][r] = 0;
            q.push(r);
        }
        while (!q.empty()) {
            int reg = q.front();
            q.pop();
            for (auto r : regconn[reg]) {
                if(dist[i][r] == 1000000000) {
                    dist[i][r] = dist[i][reg] + 1;
                    q.push(r);
                }
            }
        }
    }

    int minimum = 1000000000, minplace = -1;
    f0r (i, 0, M) {
        int cur = 0;
        f0r (j, 0, L) {
            cur += dist[j][i];
        }
        if (cur < minimum) {
            minimum = cur;
            minplace = i + 1;
        }
    }
    cout << minimum << endl << minplace << endl;
}