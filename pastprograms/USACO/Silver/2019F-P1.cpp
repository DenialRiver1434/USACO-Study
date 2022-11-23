#define pb push_back
#define mt make_tuple
#include <bits/stdc++.h>
using namespace std;

int N, a;
vector<int> cp;

	int getCompressedIndex(int a, vector<int> indices) {
		return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
	}
int main() {
    ifstream fin;
    ofstream fout;
    fin.open("herding.in");
    fout.open("herding.out");
    fin >> N;
    for (int i = 0; i < N; i ++) {
        fin >> a;
        cp.pb(a);
    }
    sort(cp.begin(), cp.end());
    if((cp[N - 1] - cp[1]) == (N - 2) && (cp[1] - cp[0]) > 2) fout << 2 << endl;
    else if((cp[N - 2] - cp[0]) == (N - 2) && (cp[N - 1] - cp[N - 2]) > 2) fout << 2 << endl;
    else {
        int best = 0;
        for (int i = 0; i < N; i ++) {
            int lim = cp[i] + N;
            int diff = lower_bound(cp.begin(), cp.end(), lim) - cp.begin() - i;
            best = max(best, diff);
        }
        fout << (N - best) << endl;
    }
    fout << (max(cp[N - 2] - cp[0] - (N - 2), cp[N - 1] - cp[1] - (N - 2)));
}