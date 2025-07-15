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

void set_min(int& a, const int& b) {
	if (b<a) a=b;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s, e; cin >> s >> e;
	int n = s.size(), m=e.size();
	int dp[n+1][m+1];
	forn(i,n+1) forn(j,m+1) dp[i][j]=INT_MAX;
	dp[0][0]=0;
	forn(i,n) {
		forn(j,m) {
			set_min(dp[i+1][j], dp[i][j]+1);
			set_min(dp[i][j+1],dp[i][j]+1);
			if (s[i]==e[j]) {
				set_min(dp[i+1][j+1],dp[i][j]);
			}
			else set_min(dp[i+1][j+1],dp[i][j]+1);
		}
	}
	forn(i,n) set_min(dp[i+1][m], dp[i][m]+1);
	forn(i,m) set_min(dp[n][i+1], dp[n][i]+1);
	// forn(i,n+1) {
	// 	forn(j,m+1) cout << dp[i][j] spc;
	// 	nl;
	// }
	cout << dp[n][m];
}
