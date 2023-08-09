#include <bits/stdc++.h>
using namespace std;

const int NO_WORK = 1e9;

void testcase () {
    int W, H; cin >> W >> H; // the room
    int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2; // the first table
    int w, h; cin >> w >> h; // the second table

    int moveright, moveleft, moveup, movedown;
    if ((w + x2 - x1) > W) { // Testing whether putting the tables left-to-right fits at all
        moveright = NO_WORK;
        moveleft = NO_WORK;
    }
    else {
        moveright = max(0, w - x1);
        moveleft = max(0, x2 - (W - w));
    }

    if ((h + y2 - y1) > H) { 
        moveup = NO_WORK;
        movedown = NO_WORK;
    }
    else {
        moveup = max(0, h - y1);
        movedown = max(0, y2 - (H - h));
    }

    int ans = min(min(moveright, moveleft), min(moveup, movedown));
    if(ans == NO_WORK) { // no options work
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
}

int main() {
    int T; cin >> T;
    while (T --) {
        testcase ();
    }
}