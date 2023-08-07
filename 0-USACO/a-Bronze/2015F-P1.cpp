#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#include <bits/stdc++.h>
using namespace std;

string S, T;

int main() {
	fileread ("censor");
	fin >> S >> T;
	string output;
	int lT = T.size(); // storing the size of T for convenience

	/* 
	 * We simulate the process of censoring by recreating the 
	 * string one letter at a time from left to right and
	 * checking if the suffix (last few letters) are the banned
	 * word.
	*/
	for (auto ch : S) {
		output += ch; // += runs in O(1) time
		if(output.size() >= lT) {
			if(output.substr(output.size() - lT, lT) == T) {
				// Remove the banned suffix
				for (int i = 0; i < lT; i ++) output.pop_back(); 
			}
		}
	}
	fout << output << endl;
}