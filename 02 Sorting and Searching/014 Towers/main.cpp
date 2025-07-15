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
	multiset<int> tt;
	forn(i,n) {
		if (tt.upper_bound(k[i]) == tt.end()) tt.insert(k[i]);
		else {
			tt.erase(tt.upper_bound(k[i]));
			tt.insert(k[i]);
		}
	}
	cout << tt.size();
}
