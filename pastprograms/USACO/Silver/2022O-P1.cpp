#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
long long N, dest, point;
vector<long long> mooc, dirs;
vector<vector<long long>> cycles;
set<long long> inlist, rotlist;

int main() {
    cin >> N;
    for(int i = 0; i < N; i ++) {
        cin >> dest >> point;
        dirs.push_back(dest - 1);
        mooc.push_back(point);
    }
    for(int i = 0; i < N; i ++){
        vector<long long> past = {i};
        set<long long> pastghost = {i};
        long long cow = i;
        if (inlist.find(cow) != inlist.end() || rotlist.find(cow) != rotlist.end()) continue;
        while(true) {
            cow = dirs[cow];
            if (inlist.find(cow) != inlist.end() || rotlist.find(cow) != rotlist.end()) {
                past.push_back(cow);
                pastghost.insert(cow);
                for(auto p : past){
                    if(inlist.find(p) == inlist.end() && rotlist.find(p) == rotlist.end()) inlist.insert(p);
                    else break;
                }
            }
            if (pastghost.find(cow) != pastghost.end()){
                short passed = 0;
                vector<long long> late;
                for (auto p : past){
                    if(p == cow) passed = 1;
                    if(passed == 1) {
                        late.push_back(p);
                        rotlist.insert(p);
                    }
                    else inlist.insert(p);
                }
                cycles.push_back(late);
                break;
            }
            past.push_back(cow);
            pastghost.insert(cow);
        }
    }

    long long tc = 0;
    for(auto i : inlist) tc += mooc[i];
    for(auto c : cycles){
        long long worst = mooc[c[0]];
        for (auto n : c){
            tc += mooc[n];
            worst = min(worst, mooc[n]);
        }
        tc -= worst;
    }
    cout << tc;
}