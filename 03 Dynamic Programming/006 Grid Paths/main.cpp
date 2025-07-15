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
	bool g[n][n];
	forn(i,n) {
		string temp; cin >> temp;
		forn(j,n) {
			if (temp[j] == '.') g[i][j] = true;
			else g[i][j] = false;
		}
	}
	int dp[n+1][n+1];
	forn(i,n) forn(j,n) dp[i][j]=0;
	dp[0][0] = 1;
	forn(i,n) {
		forn(j,n) {
			if (g[i][j]) {
				dp[i+1][j] += dp[i][j];
				dp[i+1][j] %= MOD;
				dp[i][j+1] += dp[i][j];
				dp[i][j+1] %= MOD;
			}
		}
	}
	// forn(i,n) {
	// 	forn(j,n) cout << dp[i][j] spc;
	// 	cout el;
	// }
	if (g[n-1][n-1]) cout << dp[n-1][n-1];
	else cout << 0;
}
