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
    int x,n; cin >> x >> n;
	set<int> lp;
	lp.insert(0);
	lp.insert(x);
	multiset<int> rl;
	rl.insert(x);
	forn(q,n) {
		int sl; cin >> sl;
		auto ptr = lp.upper_bound(sl);
		int rs = *ptr-*(--ptr);
		rl.erase(rl.find(rs));
		rl.insert(sl-*ptr);
		rl.insert(*(++ptr)-sl);
		lp.insert(sl);
		cout << *(--rl.end()) spc;
	}
}
