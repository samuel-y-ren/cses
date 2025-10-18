// File: main.cpp
// Author: Samuel Ren
// Created: 2025-09-18 21:37:27 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int x[n]; for (int i=0; i<n; ++i) cin >> x[i];
    ll ps[n+1]; ps[0]=0;
    for (int i=0; i<n; ++i) ps[i+1]=ps[i]+x[i];
    ll dp[n+1][n+1];
    for (int i=0; i<=n; ++i) for (int j=0; j<=n; ++j) dp[i][j]=1000000000000000000ll;
    for (int i=0; i<=n; ++i) for (int j=i+1; j<=n; ++j) dp[i][j]=1000000000000000000ll;
    for (int i=0; i<n; ++i) dp[i][i+1]=0;
    for (int i=0; i<n-1; ++i) dp[i][i+2]=x[i]+x[i+1];
    int ptr[n]; for (int i=0; i<n; ++i) ptr[i]=i+1;
    for (int i=3; i<=n; ++i) {
        for (int j=0; j<=n-i; ++j) {
            dp[j][j+i]=dp[j][ptr[j]]+dp[ptr[j]][j+i];
            while (++ptr[j] && dp[j][ptr[j]]+dp[ptr[j]][j+i]<=dp[j][j+i]) dp[j][j+i]=dp[j][ptr[j]]+dp[ptr[j]][j+i];
            --ptr[j];
            dp[j][j+i]+=ps[j+i]-ps[j];
        }
    }
    // for (int i=0; i<=n; ++i) {
    //     for (int j=0; j<=n; ++j) {
    //         if (dp[i][j]>=1000000000000000000) cout << -1 << ' ';
    //         else cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[0][n];
}
