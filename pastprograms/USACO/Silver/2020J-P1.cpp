#define pb push_back
#define mt make_tuple
#define is insert
#include <bits/stdc++.h>
using namespace std;

int N, K, a, fake;
multiset<int> nums;

bool cmp(int a, int b) {
	return (a % fake) > (b % fake);
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("berries.in");
    fout.open("berries.out");

    fin >> N >> K;
    for (int i = 0; i < N; i ++) {
        fin >> a;
        nums.is(a);
    }

    int best = 0;
    for (int target = 1; target <= *nums.rbegin(); target ++) {
        fake = target;
        vector<int> leftover;
        int ready = 0;
        for (auto n : nums) {
            leftover.pb(n);
            ready += (n / target);
        }
        sort(leftover.begin(), leftover.end(), cmp);
        if(ready < (K / 2)) {
            break;
        }
        else if(ready >= K) {
            best = max(best, target * (K / 2));
        }
        else {
            int begin = target * (ready - (K / 2));
            for(int i = 0; i < N && i + ready < K; i ++) {
                begin += leftover[i] % target;
            }
            best = max(best, begin);
        }
    }
    fout << best;
}