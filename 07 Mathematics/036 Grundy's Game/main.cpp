// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-06 11:37:29 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    const int mn=1500;
    int dp[mn+1];
    dp[1]=dp[2]=0;
    for (int i=3; i<=mn; ++i) {
        bool e[i]={};
        for (int j=1; j<(i+1)/2; ++j) e[dp[j]^dp[i-j]]=true;
        for (int j=0; j<i; ++j) if (!e[j]) {
            dp[i]=j;
            break;
        }
    }
    while (t--) {
        int n; cin >> n;
        if (n>mn) cout << "first\n";
        else cout << (dp[n] ? "first\n" : "second\n");
    }
}
