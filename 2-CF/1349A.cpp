#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

map<int, multiset<int>> counts;

map<int, int> primefactorize(int N) {
    map<int, int> primefactors;
    int tester = 2, c;
    while (N != 1) {
        c = 0;
        while ((tester * tester) <= N) {
            if((N % tester) == 0) {
                c = 0;
                while ((N % tester) == 0) {
                    N /= tester;
                    c ++;
                }
                primefactors[tester ++] = c;
                break;
            }
            tester ++;
        }
        if (!c) {
            primefactors[N] = 1;
            break;
        }
    }
    return primefactors;
}

bool isprime (int n) {
    for (int i = 2; (i * i) <= n ; i ++) {
        if((n % i) == 0) return false;
    }
    return true;
}

int main () {
    int N; cin >> N;
    for (int i = 2; i < 200000; i ++) {
        if(isprime(i)) counts[i] = {};
    }
    
    for (int i = 0; i < N; i ++) {
        int a; cin >> a;
        map<int, int> nums = primefactorize(a);
        for (auto n : nums) {
            counts[n.first].is(n.second);
        }
    }
    ll ret = 1;
    for (auto co : counts) {
        int prime = co.first; multiset<int> nums = co.second; int siz = nums.size();
        if(siz == N) {
            auto itr = nums.begin();
            itr ++;
            ret *= pow(prime, *itr);
        }
        else if ((siz + 1) == N) {
            auto itr = nums.begin();
            ret *= pow(prime, *itr);
        }
    }
    cout << ret;
}