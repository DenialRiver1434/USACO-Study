#include <fstream>
#include <tuple>
#include <set>
#include <vector>
using namespace std;

int N, M, a, b;
vector<int> connections[100001];
bool searched[100001];
vector<tuple<int, int>> coords;
vector<vector<int>> societies;
vector<int> searching;

void dfs(int pos) {
    searched[pos] = true;
    searching.push_back(pos);
    for (auto i : connections[pos]) { 
        if(!searched[i]) dfs(i);
    }
}

int main() {   
    ifstream fin;
    fin.open("fenceplan.in");
    ofstream fout;
    fout.open("fenceplan.out");
    
    fin >> N >> M;

    for (int i = 0; i < N; i ++) {
        fin >> a >> b;
        coords.push_back(make_tuple(a, b));
    }

    for (int i = 0; i < M; i ++) {
        fin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    for (int i = 1; i < N + 1; i ++) {
        if(searched[i]) continue;
        searching.clear();
        dfs(i);
        societies.push_back(searching);
    }
    int best = 1000000000;
    for (auto society : societies) {
        int hx = 0, lx = 1000000000, hy = 0, ly = 1000000000;
        for (auto cow : society) {
            int a = get<0>(coords[cow - 1]), b = get<1>(coords[cow - 1]);
            hx = max(hx, a); lx = min(lx, a); hy = max(hy, b); ly = min(ly, b);
        }
        best = min(best, abs(hx - lx) + abs(hy - ly));
    }
    fout << best * 2;
}