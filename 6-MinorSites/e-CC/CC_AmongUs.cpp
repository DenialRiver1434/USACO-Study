#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

set<int> connsame[500000], conndiff[500000], conn[500000], group, diffgroup[500000];
int same[500000], red[500000], membership[500000];
bool grouped[500000], searched[500000], parasite[500000];
int redc = 0, blackc = 0, cou;
bool works;

void rdfs(int pos, int color) {
    if(!works) return;
    if(red[pos] == 0) {
        if(color == 1) redc += membership[pos];
        else blackc += membership[pos];
        red[pos] = color;
        for (auto c : diffgroup[pos]) rdfs(c, -color); 
    }
    else if(red[pos] != color) {
        works = false;
    }
}

void dfs2 (int pos, int color) {
    if(searched[pos]) return;
    searched[pos] = true;
    cou ++;
    same[pos] = color;
    for (auto c : connsame[pos]) dfs2(c, color);
}

void dfs (int pos) {
    if(grouped[pos]) return;
    grouped[pos] = true;
    group.is(pos);
    for (auto c : conn[pos]) dfs(c);
}

int main () {
	int T;
    cin >> T;
    while (T --) {
        int N, Q;
        cin >> N >> Q;
        works = true;
        int best = 0;

        for (int i = 0; i < N; i ++) {
            connsame[i].clear();
            conn[i].clear();
            conndiff[i].clear();
            searched[i] = false;
            parasite[i] = false;
            grouped[i] = false;
        }
        for (int i = 0; i < Q; i ++) {
            int a, b, c;
            cin >> a >> b >> c;
            b --; c --;
            conn[b].is(c);
            conn[c].is(b);
            if(a == 1) {
                conndiff[b].is(c);
                conndiff[c].is(b);
            }
            else {
                connsame[b].is(c);
                connsame[c].is(b);
            }
        }
        for (int i = 0; i < N; i ++) {
            if(!grouped[i]) {
                group.clear();
                dfs(i);
                int assignment = 0;
                for (int i = 0; i < 500000; i ++) {
                    if(diffgroup[i].empty()) break;
                    diffgroup[i].clear();
                    red[i] = 0;
                    membership[i] = 0;
                }
                for (int i = 0; i < 500000; i ++) {
                    if(!red[i]) break;
                    red[i] = 0;
                    membership[i] = 0;
                }
                for (auto g : group) {
                    if(!searched[g]) {
                        cou = 0;
                        dfs2(g, assignment);
                        membership[assignment++] = cou;
                    }
                }
                for (auto g : group) {
                    for (auto d : conndiff[g]) {
                        int g1 = same[g];
                        int g2 = same[d];
                        diffgroup[g1].is(g2);
                        diffgroup[g2].is(g1);
                    }
                }
                for (int i = 0; i < assignment; i ++) {
                    if(!red[i]) {
                        redc = 0; blackc = 0;
                        rdfs(i, 1);
                        best += max(redc, blackc);
                        if(!works) break;
                    }
                }
            }
            if(!works) break;
        }
        if(!works) cout << -1 << endl;
        else cout << best << endl;
    }
}