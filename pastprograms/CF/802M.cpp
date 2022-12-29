#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> nums;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        int a;
        cin >> a;
        nums.pb(a);
    }
    sort(nums.begin(), nums.end());
    int c = 0;
    for (int i = 0; i < M; i ++) {
        c += nums[i];
    }
    cout << c;
}