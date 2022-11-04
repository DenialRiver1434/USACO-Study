#include <vector>
#include <iostream>
using namespace std;

int N, M, a, b, searchc = 0, rsearchc = 0;
vector<int> connect[100001];
vector<int> revconnect[100001];
bool searched[100001];
bool revsearched[100001];

void dfs(int pos) {
    if(searched[pos]) return;
    searchc ++;
    searched[pos] = true;
    vector<int> connections = connect[pos];
    for(auto c : connections) dfs(c);
}

void revdfs(int pos) {
    if(revsearched[pos]) return;
    rsearchc ++;
    revsearched[pos] = true;
    vector<int> connections = revconnect[pos];
    for(auto c : connections) revdfs(c);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i ++ ) {
        cin >> a >> b;
        connect[a].push_back(b);
        revconnect[b].push_back(a);
    }
    dfs(1);
    revdfs(1);
    if(searchc == N && rsearchc == N) cout << "YES";
    else if (rsearchc == N) {
        cout << "NO" << endl;
        for(int i = 2; i < N + 1; i ++) {
            if(!searched[i]) {
                cout << "1 " << i;
                break;
            }
        }
    }
    else {
        cout << "NO" << endl;
        for(int i = 2; i < N + 1; i ++) {
            if(!revsearched[i]) {
                cout << i << " 1";
                break;
            }
        }
    }
}