#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int N, M, score = 0; 
vector<int> nums; set<int> avaliable;

void trim () {
    while (avaliable.size() > 1) {
        int left = nums[*avaliable.begin()], right = nums[*avaliable.rbegin()];
        if((right == left) || (right + left) == M) {
            score ++;
            avaliable.erase(*avaliable.begin());
            avaliable.erase(*avaliable.rbegin());
        }
        else break;
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N >> M; 
    for_loop (i, 0, N) {
        int a;
        cin >> a;
        nums.pb(a);
        avaliable.is(i);
    }

    trim();
    auto left = avaliable.begin(); auto right = next(left);
    while (right != avaliable.end()) {
        bool trimmed = false;
        while((nums[*left] == nums[*right]) || (nums[*left] + nums[*right]) == M) {
            score ++;
            trimmed = (left == avaliable.begin() || *right > *avaliable.rbegin());
            if(trimmed) {
                avaliable.erase(left);
                avaliable.erase(right);
                trim();
                break;
            }
            else {
                left = prev(left);
                avaliable.erase(next(left));
                right = next(right);
                avaliable.erase(prev(right));
            }
        }

        if(trimmed) {
            left = avaliable.begin(), right = next(left);
        }
        else {
            left = right;
            right = next(right);
        }
    }
    cout << score;
}