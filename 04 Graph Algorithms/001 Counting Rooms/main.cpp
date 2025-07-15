#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define el << '\n'
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define forl(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353 
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"

int n, m;
bool g[1002][1002]={0};
bool v[1002][1002]={0};
int t=0;

void ff(int s, int x, int y) {
	if (!g[x][y] | v[x][y]) return;
	if (s) t++;
	v[x][y]=true;
	ff(0,x+1,y);
	ff(0,x-1,y);
	ff(0,x,y+1);
	ff(0,x,y-1);
	return;
}

int main() {
	cin >> n >> m;
	forn(i,n) {
		string l; cin >> l;
		forn(j,m) {
			if (l[j] == '.') g[i+1][j+1] = true;
		}
	}
	forl(i,1,n+1) {
		forl(j,1,m+1) {
			ff(1,i,j);
		}
	}
	cout << t;
}