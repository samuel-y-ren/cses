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
    int n, m; cin >> n >> m;
	int dp[n][m+2];
	forn(i,n) forn(j,m+2) dp[i][j]=0;
	int x[n];
	cina(x,n);
	forn(i,m+2) dp[0][i]=1;
	forn(i,n-1) {
		if (x[i]) {
			dp[i+1][x[i]+1] += dp[i][x[i]];
			dp[i+1][x[i]+1] %= MOD;
			dp[i+1][x[i]] += dp[i][x[i]];
			dp[i+1][x[i]] %= MOD;
			dp[i+1][x[i]-1] += dp[i][x[i]];
			dp[i+1][x[i]-1] %= MOD;
		}
		else {
			forl(j,1,m+1) {
				dp[i+1][j+1] += dp[i][j];
				dp[i+1][j+1] %= MOD;
				dp[i+1][j] += dp[i][j];
				dp[i+1][j] %= MOD;
				dp[i+1][j-1] += dp[i][j];
				dp[i+1][j-1] %= MOD;
			}
		}
	}
	if (x[n-1]) cout << dp[n-1][x[n-1]];
	else {
		int tot=0;
		forl(i,1,m+1) {
			tot += dp[n-1][i];
			tot %= MOD;
		}
		cout << tot;
	}
	// forn(i,m+2) {
	// 	forn(j,n) cout << dp[j][i] spc;
	// 	cout el;
	// }
}
