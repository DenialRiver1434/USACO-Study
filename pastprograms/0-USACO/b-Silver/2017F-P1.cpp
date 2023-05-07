#define pb push_back
#define mt make_tuple
#define is insert
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
bool cmp(tuple<int, int> a, tuple<int, int> b) {
	return get<1>(a) < get<1>(b);
}
multiset<tuple<int, int>, decltype(cmp)*> avaliable(cmp);
multiset<tuple<int, int>> frontcows;
multiset<int> chickens;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("helpcross.in");
    fout.open("helpcross.out");

    fin >> N >> M;
    while (N --) {
        fin >> a;
        chickens.is(a);
    }
    while (M --) {
        fin >> a >> b;
        frontcows.is(mt(a, b));   
    }
    int count = 0;
    for (auto c : chickens) {
        while(!frontcows.empty()) {
            auto first = *frontcows.begin();
            if(get<0>(first) > c) break;
            frontcows.erase(frontcows.find(first));
            avaliable.is(first);
        }
        while(!avaliable.empty()) {
            auto first = *avaliable.begin();
            if(get<1>(first) >= c) break;
            avaliable.erase(avaliable.find(first));
        }
        if(!avaliable.empty()) {
            count ++;
            avaliable.erase(avaliable.find(*begin(avaliable)));
        }
    }
    fout << count;
}