#include <set>
#include <vector>
#include <fstream>
using namespace std;
int N, Tmax;
vector<int> times;

bool test (int X){
    multiset<int> findmin;
    int tt = 0, worst = 0;
    for(int i = 0; i < X; i ++){ 
        worst = max(worst, times[i]);
        findmin.insert(times[i]);
    }
    for(int i = X; i < N; i ++){
        int lowest = *findmin.begin();
        int addition = lowest + times[i];
        findmin.erase(findmin.begin());
        findmin.insert(addition);
        worst = max(worst, addition);
    }

    return worst <= Tmax;
}

int main() {
    ifstream fin;
    fin.open("cowdance.in");
    ofstream fout;
    fout.open("cowdance.out");
    fin >> N >> Tmax;

    for(int i = 0; i < N; i ++){
        int a;
        fin >> a;
        times.push_back(a);
    }

    int lb = 1, ub = N;
    while(ub > lb) {
        int mid = (ub + lb) / 2;
        if(test(mid)) ub = mid;
        else lb = mid;

        if (ub == (lb + 1) && test(lb)) {
            fout << lb;
            break;
        }
        else if (ub == (lb + 1)) {
            fout << ub;
            break;
        }
        else if (ub == lb){
            fout << ub;
            break;
        }
    }
}