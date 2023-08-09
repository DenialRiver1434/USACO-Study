#include <bits/stdc++.h>
using namespace std;
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")

int intersection(int a, int b, int c, int d){
    return max(0, min(b,d)-max(a,c));
}

int main() {
    fileread("paint");
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    fout << (b + d - a - c - intersection(a, b, c, d)) << endl;
}