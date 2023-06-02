#define pb push_back
#define mt make_tuple
#define is insert
#include <bits/stdc++.h>
using namespace std;

int N, a, b;
priority_queue<tuple<int, int, int>> pq;
vector<tuple<int, int, int>> order;

bool rcomp (tuple<int, int, int> a, tuple<int, int, int> b) {
    if(get<0>(a) == get<0>(b)) return get<2>(a) > get<2>(b);
    return get<0>(a) > get<0>(b);
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("convention2.in");
    fout.open("convention2.out");

    fin >> N;
    int worse = 0, end = 0;
    for (int i = 0; i < N; i ++) {
        fin >> a >> b;
        order.pb(mt(a, b, i));
    }
    sort(order.begin(), order.end(), rcomp);
    while(!pq.empty() || !order.empty()) { // Repeat every new cow in enclosure
        if(pq.empty()) { // there was a period where nobody is here
            auto nums = order[order.size() - 1];
            order.pop_back();
            int start = get<0>(nums), time = get<1>(nums), priority = get<2>(nums);
            end = start + time; // begins
        }
        else {
            auto nums = pq.top();
            pq.pop();
            int start = get<1>(nums), time = get<2>(nums);
            worse = max(worse, end - start);
            end += time;
        }
        while(!order.empty()) {
            auto nums = order[order.size() - 1];
            int start = get<0>(nums), time = get<1>(nums), priority = get<2>(nums);
            if(start > end) break;
            order.pop_back();
            pq.push(mt(N - priority, start, time));
        }
    }
    fout << worse;
}