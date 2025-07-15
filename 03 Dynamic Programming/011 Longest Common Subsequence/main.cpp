// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-12 21:33:35 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	int a[n+1], b[m+1]; 
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<m; i++) cin >> b[i];
	a[n]=2000000000; b[m]=-2000000000;
	n++; m++;
	pair<int,pair<int,int>> dp[n+1][m+1]; 
	for (int i=0; i<=n; i++) dp[i][0]={0,{-1,-1}};
	for (int i=0; i<=m; i++) dp[0][i]={0,{-1,-1}};
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
		dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		if (a[i-1]==b[j-1]) {
			dp[i][j]=dp[i-1][j-1];
			dp[i][j].first++;
			dp[i][j].second={i,j};
		}
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (a[i-1]==b[j-1]) {
		if (i && b && a[i-2]==b[j-2]) dp[i][j].second={i-1,j-1};
		else dp[i][j].second=dp[i-1][j-1].second;
	}
	int l=dp[n][m].first;
	cout << l << '\n';
	pair<int,int> cp=dp[n][m].second;
	vector<int> p;
	for (int i=0; i<l; i++) {
		p.push_back(a[cp.first-1]);
		cp=dp[cp.first][cp.second].second;
	}
	for (int i=l-1; i>=0; i--) cout << p[i] << ' ';
}
