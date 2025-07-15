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
#define cina(arr, n) for (int i=0; i<n; i++) cin >> arr[i]
#define fi first
#define se second
#define pii pair<int,int>
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n; cin >> n;
	int k[n];
	cina(k,n);
	set<int> uk;
	forn(i,n) uk.insert(k[i]);
	int m = uk.size();
	int rcc[m];
	auto ptr = uk.begin();
	forn(i,m) {
		rcc[i] = *ptr;
		ptr++;
	}
	map<int,int> cc;
	forn(i,m) cc[rcc[i]] = i;
	forn(i,n) k[i] = cc[k[i]];
	vector<int> p[m];
	forn(i,n) p[k[i]].pb(i);
	forn(i,m) p[i].pb(n);
	int nd[n];
	for (vector<int> dl : p) {
		forn(i,dl.size()-1) {
			nd[dl[i]] = dl[i+1];
		}
	}
	// forn(i,n) cout << nd[i] spc;
	int p1=0, p2=0;
	int bl[n+1]={0};
	int mc=0;
	while (p2<n) {
		if (!bl[p2]) {
			bl[nd[p2]]+=1;
			p2++;
			mc=max(mc,p2-p1);
		}
		else {
			bl[nd[p1]]-=1;
			p1++;
		}
	}
	cout << mc << endl;
}
