#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N;
string st, en, a, b;
map<string, string> mother;

int main() {
    ifstream fin; ofstream fout;
    fin.open("family.in"); fout.open("family.out");

    fin >> N >> st >> en;
    for (int i = 0; i < N; i ++) {
        fin >> a >> b;
        mother[b] = a;
    }

    int cs = 0, ce = 0;
    string reader = st;
    while (mother.find(reader) != mother.end()) {
        reader = mother[reader];
        cs ++;
    }
    reader = en;
    while (mother.find(reader) != mother.end()) {
        reader = mother[reader];
        ce ++;
    }
    if(ce > cs) swap(st, en);
    
    if(mother.find(st) == mother.end()) {
        fout << "NOT RELATED";
        return 0;
    }


    vector<string> chainst = {};
    set<string> chains;
    reader = st;
    int c = -1;
    while (mother.find(reader) != mother.end()) {
        reader = mother[reader];
        if (reader == en) {
            if (c == -1) {
                fout << en << " is the mother of " << st;
                return 0;
            }
            fout << en << " is the ";
            while (c --) fout << "great-";
            fout << "grand-mother of " << st;
            return 0;
        }
        chainst.pb(reader);
        chains.is(reader);
        c ++;
    }
    int cc = chainst.size();

    if(mother.find(en) != mother.end()) {
        if(mother[st] == mother[en]) {
            fout << "SIBLINGS";
            return 0;
        }
        string helper = mother[en];
        for (int i = 1; i < cc; i ++) {
            if (chainst[i] == helper) {
                fout << en << " is the ";
                i --;
                while ((i --) > 0) {
                    fout << "great-";
                }
                fout << "aunt of " << st;
                return 0;
            }
        }
        string reader = mother[en];
        while (mother.find(reader) != mother.end()) {
            reader = mother[reader];
            if (chains.find(reader) != chains.end()) {
                fout << "COUSINS";
                return 0;
            }
        }
        fout << "NOT RELATED";
        return 0;
    }
    else {
        fout << "NOT RELATED";
        return 0;
    }
}