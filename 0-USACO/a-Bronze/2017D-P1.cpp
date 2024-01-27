#include <bits/stdc++.h>
using namespace std;
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")

int intersection1D (int a, int b, int c, int d) {
    return max(0, min(b,d)-max(a,c));
}

int intersection2D (tuple<int, int, int, int> rect1, tuple<int, int, int, int> rect2) {
    // tying into tuples makes code slightly cleaner
    int rect1x1, rect1y1, rect1x2, rect1y2;
    tie(rect1x1, rect1y1, rect1x2, rect1y2) = rect1;

    int rect2x1, rect2y1, rect2x2, rect2y2;
    tie(rect2x1, rect2y1, rect2x2, rect2y2) = rect2;
    return intersection1D(rect1x1, rect1x2, rect2x1, rect2x2) * intersection1D(rect1y1, rect1y2, rect2y1, rect2y2);
}

int main() {
    fileread("billboard");
    int rect1x1, rect1y1, rect1x2, rect1y2; // first rectangle
    fin >> rect1x1 >> rect1y1 >> rect1x2 >> rect1y2;

    int rect2x1, rect2y1, rect2x2, rect2y2; // second rectangle
    fin >> rect2x1 >> rect2y1 >> rect2x2 >> rect2y2;

    int truckx1, trucky1, truckx2, trucky2; // truck
    fin >> truckx1 >> trucky1 >> truckx2 >> trucky2;

    int ans = (rect1x2 - rect1x1) * (rect1y2 - rect1y1) + (rect2x2 - rect2x1) * (rect2y2 - rect2y1);
    ans -= intersection2D({rect1x1, rect1y1, rect1x2, rect1y2}, {truckx1, trucky1, truckx2, trucky2});
    ans -= intersection2D({rect2x1, rect2y1, rect2x2, rect2y2}, {truckx1, trucky1, truckx2, trucky2});
    
    fout << ans << endl;
}