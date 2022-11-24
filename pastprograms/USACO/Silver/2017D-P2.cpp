#define pb push_back
#define mt make_tuple
#define is insert
#include <bits/stdc++.h>
using namespace std;

int N, G, a, b, c;
char sign;
map<int, int> prod;
map<int, set<int>> reverseprod;
map<int, vector<tuple<int, int>>> changes;

int main() {
    ifstream fin;
    fin.open("measurement.in");
    ofstream fout;
    fout.open("measurement.out");

    fin >> N >> G;
    prod[0] = G;
    reverseprod[G] = {0};
    for (int i = 0; i < N; i ++) {
        fin >> a >> b >> sign >> c;
        if(sign == '-') c *= -1;
        if(changes.find(a) == changes.end()) {
            changes[a] = {mt(b, c)};
        }
        else {
            changes[a].pb(mt(b, c));
        }
        prod[b] = G;
        reverseprod[G].is(b);
    }
    
    int c = 0;
    for (auto pair : changes) {
        int highest = reverseprod.rbegin() -> first;
        vector<tuple<int, int>> log = pair.second;
        set<int> initial = reverseprod[highest];
        for (auto l : log) {
            int affected = get<0>(l), change = get<1>(l);
            reverseprod[prod[affected]].erase(affected);
            if(reverseprod[prod[affected]].empty()) {
                reverseprod.erase(prod[affected]);
            }
            prod[affected] += change;
            if(reverseprod.find(prod[affected]) == reverseprod.end()) reverseprod[prod[affected]] = {affected};
            else reverseprod[prod[affected]].is(affected);
        }
        set<int> after = reverseprod[reverseprod.rbegin() -> first];
        if(initial != after) {
            c ++;
        }
    }
    fout << c;
}