#define pb push_back
#define mt make_tuple
#include <bits/stdc++.h>
using namespace std;

int N, M, a;
vector<int> nums;

int main() {
    ifstream fin;
    fin.open("diamond.in");
    ofstream fout;
    fout.open("diamond.out");
    fin >> N >> M;
    for (int i = 0; i < N; i ++) {
        fin >> a;
        nums.pb(a);
    }
    sort(nums.begin(), nums.end());
    vector<int> sizes, msizes;
    for (int i = 0; i < N; i ++) {
        int ni = nums[i];
        int os = lower_bound(nums.begin(), nums.end(), ni + M + 1) - nums.begin();
        sizes.pb(os - i);
    }
    sizes.pb(0);
    int rs = 0;
    for (int i = N; i >= 0; i --) {
        rs = max(rs, sizes[i]);
        msizes.pb(rs);
    }
    int best = 0;
    for (int i = 0; i < N; i ++) {
        int si = sizes[i];
        int startpos = i + si;
        best = max(best, si + msizes[(N - startpos)]);
    }
    fout << best;
}