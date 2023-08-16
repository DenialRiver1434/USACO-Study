// Math solution O(1)

#include <bits/stdc++.h> 
using namespace std;

int main () {     
    ifstream fin; fin.open("walk.in");
    ofstream fout; fout.open("walk.out");

    long long N, K; 
    fin >> N >> K;
    if (K == 1) { fout << 0 << endl; }
    else { fout << 2019202081LL - 84LL * K - 48LL * N << endl; }
}