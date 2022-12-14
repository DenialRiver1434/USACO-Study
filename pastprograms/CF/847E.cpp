#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N; char a;
set<int> coinss, pacs;

bool test (int num) {
    set<int> coins;
    for (auto co : coinss) coins.is(co);
    for (auto c : pacs) {
        int time = num;
	    int prev = *coins.begin();
        if(prev < c) {
            if((c - prev) > num) return false;
            int space = (c - prev), fin;
            if((3 * space) <= time) {
                time -= space;
                fin = prev + time;
            }
            else {
                time -= space;
                fin = c + (time) / 2;
            }
            while (!coins.empty()) {
                int firs = *coins.begin();
                if(firs <= fin) coins.erase(firs);
                else break;
            }
            if(coins.empty()) {
                return true;
            }
        }
        else {
            time += c;
            while (!coins.empty()) {
                int firs = *coins.begin();
                if(firs <= time) coins.erase(firs);
                else break;
            }
            if(coins.empty()) {
                return true;
            }
        }
    }
    return coins.empty();
}

int first_true(int lo, int hi) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> a;
        if(a == '*') coinss.is(i);
        else if(a == 'P') pacs.is(i);
    }
    cout << first_true(1, 2e5);
}
