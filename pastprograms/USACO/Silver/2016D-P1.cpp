#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, Q, a, b;
vector<int> nums;


int main() {
    ifstream fin;
    ofstream fout;
    fin.open("haybales.in");
    fout.open("haybales.out");
    fin >> N >> Q;
    while(N --) {
        fin >> a;
        nums.pb(a);
    }
    sort(nums.begin(), nums.end());
    while (Q --) {
        fin >> a >> b;
        int low = lower_bound(nums.begin(), nums.end(), a) - nums.begin();
        int up = upper_bound(nums.begin(), nums.end(), b) - nums.begin();
        fout << (up - low) << endl;
    }
}