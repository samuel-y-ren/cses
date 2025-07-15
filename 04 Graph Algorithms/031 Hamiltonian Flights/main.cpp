#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
#pragma GCC optimize("Ofast")

int main() {
	int n,m; cin >> n >> m;
	short a[n][n]; 
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) a[i][j]=0;
	while (m--) {
		int x,y; cin >> x >> y;
		a[x-1][y-1]++;
	}
	int k = 1<<n;
	long long dp[n][k];
	for (int i=0; i<n; i++) for (int j=0; j<k; j++) dp[i][j]=0;
	dp[0][1]=1;
	vector<int> pc[n+1];
	vector<short> bt[k];
	for (int i=0; i<k; i++) {
		pc[__builtin_popcount(i)].push_back(i);
		for (int j=0; j<n; j++) if (i & (1<<j)) bt[i].push_back(j);
	}
	for (int c=1; c<n; c++) for (int m : pc[c]) for (short i : bt[m]) {
		if (!dp[i][m]) continue;
		dp[i][m] %= MOD;
		for (short j : bt[k-1-m]) dp[j][m+(1<<j)] += a[i][j]*dp[i][m];
	}
	cout << dp[n-1][k-1]%MOD;
}