#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, checkpoint = 0, cou;
set<int> blocked[200000];
set<int> notsearched;
 
void dfs (int pos) {
    cou ++;
    auto itr = notsearched.begin();
    while (itr != notsearched.end()) {
        if (blocked[pos].find(*itr) != blocked[pos].end()) {
            itr ++;
            continue;
        }
        else {
            int save = *itr;
            notsearched.erase(itr);
            dfs(save);
            itr = notsearched.upper_bound(save);
        }
    }
}
 
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        notsearched.is(i);
    }
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        a --; b --;
        blocked[a].is(b);
        blocked[b].is(a);
    }
    int c = 0;
    multiset<int> sizes;
    while(notsearched.size()) {
        auto remove = *notsearched.begin();
        cou = 0;
        notsearched.erase(remove);
        dfs(remove);
        c ++;
        sizes.is(cou);
    }
    cout << c << endl;
    for (auto s : sizes) {
        cout << s << " ";
    }
}