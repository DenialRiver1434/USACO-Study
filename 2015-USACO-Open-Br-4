
#include <bits/stdc++.h>
using namespace std;

int N;
string grid[18];
set<string> c;
map<string, set<tuple<int, int, int, int>>> paths;

bool valid(int xa, int ya, int xb, int yb){
    if (xa < 0 || xa >= N) return false;
    if (xb < 0 || xb >= N) return false;
    if (ya < 0 || ya >= N) return false;
    if (yb < 0 || yb >= N) return false;
    if(xa > xb || ya > yb) return false;
    return grid[xa][ya] == grid[xb][yb];
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> grid[i];
    }
    paths[grid[0].substr(0, 1)] = {make_tuple(0, 0, N - 1, N - 1)};
    for(int i = 0; i < N - 1; i ++){
        vector<string> keys;
        for (const auto &p : paths) keys.push_back(p.first);
        for (const auto &cur : keys){
            const set<tuple<int, int, int, int>> &coords = paths[cur];
            for (const auto &coord : coords){
                int xa = get<0>(coord), ya = get<1>(coord), xb = get<2>(coord), yb = get<3>(coord);
                if(valid(xa + 1, ya, xb - 1, yb)){
                    string add = cur + grid[xa + 1][ya];
                    if(paths.find(add) != paths.end()){ // add in path
                        paths[add].insert(make_tuple(xa + 1, ya, xb - 1, yb));
                    }
                    else paths[add] = {make_tuple(xa + 1, ya, xb - 1, yb)};
                }
                if(valid(xa, ya + 1, xb - 1, yb)){
                    string add = cur + grid[xa][ya + 1];
                    if(paths.find(add) != paths.end()){ // add in path
                        paths[add].insert(make_tuple(xa, ya + 1, xb - 1, yb));
                    }
                    else paths[add] = {make_tuple(xa, ya + 1, xb - 1, yb)};
                }
                if(valid(xa + 1, ya, xb, yb - 1)){
                    string add = cur + grid[xa + 1][ya];
                    if(paths.find(add) != paths.end()){ // add in path
                        paths[add].insert(make_tuple(xa + 1, ya, xb, yb - 1));
                    }
                    else paths[add] = {make_tuple(xa + 1, ya, xb, yb - 1)};
                }
                if(valid(xa, ya + 1, xb, yb - 1)){
                    string add = cur + grid[xa][ya + 1];
                    if(paths.find(add) != paths.end()){ // add in path
                        paths[add].insert(make_tuple(xa, ya + 1, xb, yb - 1));
                    }
                    else paths[add] = {make_tuple(xa, ya + 1, xb , yb - 1)};
                }
            }
            paths.erase(cur);
        }
    }
    cout << paths.size();
}
