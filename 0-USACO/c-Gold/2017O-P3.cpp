#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (lll i = begin; i < n; i ++)
#define len(x) x.size()
#define vi vector<lll>
#define vpi vector<pair<lll, lll>>
#include <bits/stdc++.h>
using namespace std;

vi nums;
bool cur[100001], used[100001];
int latest[100001];
stack<lll> hist;

int main() {
    ifstream fin; ofstream fout;
    fin.open("art2.in"); fout.open("art2.out");

    lll N; fin >> N;
    lll mhs = 1;
    hist.push(0);
    cur[0] = 1; used[0] = 1;

    f0r (i, 0, N) {
        lll a; fin >> a;
        nums.pb(a);
        latest[a] = i;
    }
    f0r (i, 0, N) {
        lll a = nums[i];
        if(cur[a]) {
            while(hist.top() != a) {
                cur[hist.top()] = 0;
                hist.pop();
                if(hist.empty()) {
                    fout << -1 << endl;
                    return 0;
                }
            }
        }
        else {
            if(used[a]) {
                fout << -1 << endl;
                return 0;
            }
            else {
                hist.push(a);
                cur[a] = 1;
                used[a] = 1;
            }
        }
        lll hs = hist.size();
        mhs = max(mhs, hs);
        if((latest[a] == i) && (a != 0)) hist.pop();
    }
    fout << mhs - 1 << endl;
}
