#define pb push_back
#define mp make_pair
#define ll long long
#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<ll, ll>> vpi;
vpi coords;
ll N, a, b;

bool comp (pair<ll, ll> a, pair<ll, ll> b) {
	return a.second < b.second;
}
bool rcomp (pair<ll, ll> a, pair<ll, ll> b) {
	return a.second > b.second;
}
bool llcomp (pair<ll, ll> a, pair<ll, ll> b) {
	return a.first > b.first;
}

int main() {
	ifstream fin;
	fin.open("split.in");
	ofstream fout;
	fout.open("split.out");
	fin >> N;
	ll maxx = 0, minx = 1000000000, maxy = 0, miny = 1000000000; 
	for (ll i = 0; i < N; i ++) {
		fin >> a >> b;
		maxx = max(a, maxx); minx = min(a, minx); maxy = max(b, maxy); miny = min(b, miny);
		coords.pb(mp(a, b));
	}
	ll onearea = (maxx - minx) * (maxy - miny);
	
	ll twoarea = 1000000000LL * 1000000000LL;

	//Horizontal sweep
	sort(coords.begin(), coords.end());
	//Left to right
	vector<ll> ltr;
	ll lmaxx = 0, lminx = 1000000000, lmaxy = 0, lminy = 1000000000; 
	for (auto p : coords) {
		ll a = p.first, b = p.second;
		lmaxx = max(a, lmaxx); lminx = min(a, lminx); lmaxy = max(b, lmaxy); lminy = min(b, lminy);
		ltr.pb((lmaxx - lminx) * (lmaxy - lminy));
	}
	
	sort(coords.begin(), coords.end(), llcomp);

	//Right to left
	vector<ll> rtl;
	lmaxx = 0; lminx = 1000000000; lmaxy = 0; lminy = 1000000000; 
	for (auto p : coords) {
		ll a = p.first, b = p.second;
		lmaxx = max(a, lmaxx); lminx = min(a, lminx); lmaxy = max(b, lmaxy); lminy = min(b, lminy);
		rtl.pb((lmaxx - lminx) * (lmaxy - lminy));
	}

	for (int i = 0; i < N - 1; i ++) twoarea = min(twoarea, rtl[i] + ltr[N - i - 2]);

	

	//Vertical sweep
	sort(coords.begin(), coords.end(), comp);
	//Down to up
	vector<ll> dtu;
	lmaxx = 0; lminx = 1000000000; lmaxy = 0; lminy = 1000000000; 
	for (auto p : coords) {
		ll a = p.first, b = p.second;
		lmaxx = max(a, lmaxx); lminx = min(a, lminx); lmaxy = max(b, lmaxy); lminy = min(b, lminy);
		dtu.pb((lmaxx - lminx) * (lmaxy - lminy));
	}
	
	sort(coords.begin(), coords.end(), rcomp);

	//Up to down
	vector<ll> utd;
	lmaxx = 0; lminx = 1000000000; lmaxy = 0; lminy = 1000000000; 
	for (auto p : coords) {
		ll a = p.first, b = p.second;
		lmaxx = max(a, lmaxx); lminx = min(a, lminx); lmaxy = max(b, lmaxy); lminy = min(b, lminy);
		utd.pb((lmaxx - lminx) * (lmaxy - lminy));
	}

	for (int i = 0; i < N - 1; i ++) twoarea = min(twoarea, dtu[i] + utd[N - i - 2]);
	fout << onearea - twoarea;
}