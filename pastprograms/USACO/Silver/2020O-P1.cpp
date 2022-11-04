#include <fstream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cmath>
using namespace std;
long long N, M, a, b;
vector<tuple<int, int>> intervals;

bool test(long long n) {
    long long cows = 0;
    long long ending = -1000000000000000000;
    for (auto pair : intervals){
        long long a = get<0>(pair), b = get<1>(pair);
        a = max(a, ending + n);
        long long temp = 0;
        if(b >= a) {
            long long add = max(temp, 1 + (b - a) / n);
            cows += add;
            ending = a + (add - 1) * n;
        }
    }
    return cows >= N;
}

int last_true(int lo, int hi) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (test(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int main() {
    ifstream fin;
    fin.open("socdist.in");
    ofstream fout;
    fout.open("socdist.out");

    fin >> N >> M;
    for (long long i = 0; i < M; i ++){
        fin >> a >> b;
        intervals.push_back(make_tuple(a, b));
    }
    sort(intervals.begin(), intervals.end());
    fout << last_true(1, get<1>(intervals[M-1])) << endl;
}