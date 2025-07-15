// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-04 10:35:59 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; string s; cin >> n >> s;
    int m = s.size();
    int si[m]; for (int i=0; i<m; ++i) si[i] = int(s[i])-65;
    int f[m]; f[0]=0;
    for (int i=1; i<m; ++i) {
        int j=f[i-1];
        while (j&&si[i]!=si[j]) j=f[j-1];
        f[i]=j+(si[i]==si[j]);
    }
    int k = 26;
    int fc[m][k];
    for (int i=0; i<k; ++i) fc[0][i]=0;
    fc[0][si[0]]=1;
    for (int i=1; i<m; ++i) {
        for (int j=0; j<26; ++j) {
            int l=f[i-1];
            while (l&&j!=si[l]) l=f[l-1];
            fc[i][j]=l+(j==si[l]);
        }
        fc[i][si[i]]=i+1;
    }
    // for (int i=0; i<m; ++i) {
    //     for (int j=0; j<k; ++j) cout << fc[i][j] << ' ';
    //     cout << '\n';
    // }
    ll dp[n+1][m+1]={};
    dp[0][0]=1;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            dp[i][j]%=MOD;
            for (int l=0; l<k; ++l) dp[i+1][fc[j][l]]+=dp[i][j];
        }
    }
    ll t=0, st=1;
    for (int i=n; i; --i) {
        t+=st*dp[i][m]%MOD;
        st=st*26%MOD;
    }
    cout << t%MOD;
}
