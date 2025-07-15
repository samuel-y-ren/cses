#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")
#define el << '\n'
#define nl cout << '\n'
#define cina(a,n) for (int i=0; i<n; i++) cin >> a[i]
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define forl(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<long long, long long>
#define MAX *max_element
#define MIN *min_element

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n; cin >> n;
	int mm;
	int x[n]; 
	forn(i,n) {
		cin >> x[i];
		mm+=x[i];
	}
	bool dp[mm+1]={};
	dp[0] = true;
	forn(i,n) {
		for (int j = mm; j>=x[i]; j--) {
			if (dp[j-x[i]]) dp[j] = true;
		}
	}
	int tot=0;
	forl(i,1,mm+1) if (dp[i]) tot++;
	cout << tot el;
	forl(i,1,mm+1) if (dp[i]) cout << i spc;
}
