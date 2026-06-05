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
    ll dp[n+1][n+1]; int mid[n+1][n+1];
    dp[0][1]=0;
    for (int i=2; i<=n; ++i) {
        dp[i-1][i]=0;
        dp[i-2][i]=ps[i]-ps[i-2];
        mid[i-2][i]=i-1;
        for (int j=i-3; ~j; --j) {
            dp[j][i]=1000000000000000000;
            for (int k=mid[j][i-1]; k<=mid[j+1][i]; ++k) {
                ll r=dp[j][k]+dp[k][i];
                if (r<dp[j][i]) {
                    dp[j][i]=r;
                    mid[j][i]=k;
                }
            }
            dp[j][i]+=ps[i]-ps[j];
        }
    }
    cout << dp[0][n] << '\n';

}
