#define pb push_back
#define mt make_tuple
#include <bits/stdc++.h>
using namespace std;

int N, M, num;
char a;
vector<int> letters;
vector<int> nums[26];
int ans[26][1501];

int main() {
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> a;
        letters.pb(int(a) - 97);
    }
    for (int i = 0; i < 26; i ++) {
        int count = 0;
        nums[i].pb(count);
        for (auto n : letters) {
            if(n == i) count ++;
            nums[i].pb(count);
        }
    }
    
    for (int i = 0; i < 26; i ++) {
        for (int j = 1; j <= N; j ++) { // j = size of the block
            for (int start = 1; start <= (N - j + 1); start ++) {
                int end = start + j;
                int numberofi = j - (nums[i][end - 1] - nums[i][start - 1]);
                ans[i][numberofi] = max(ans[i][numberofi], j);
            }
        }
    }
    for (int i = 0; i < 26; i ++) {
        for (int j = 1; j <= 1500; j ++) { // j = size of the block
            ans[i][j] = max(ans[i][j], ans[i][j - 1]);
        }
    }
    cin >> M;
    for (int i = 0; i < M; i ++) {
        cin >> num >> a;
        cout << ans[int(a) - 97][num] << endl;
    }
}