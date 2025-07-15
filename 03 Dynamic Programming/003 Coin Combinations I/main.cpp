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
    int n,x; cin >> n >> x;
	int c[n];
	cina(c,n);
	int dp[x+1]={0};
	dp[0]=1;
	forn(i,x) {
		for (int j : c) {
			if (i+j<=x) {
				dp[i+j] += dp[i];
				dp[i+j] %= MOD;
			}
		}
	}
	// forn(i,x) cout << dp[i] spc;
	cout << dp[x];
}
