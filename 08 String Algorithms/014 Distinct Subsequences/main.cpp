// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-08 12:52:59 PST

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = (int) s.size();
    int dp[n+1]; dp[0]=1;
    int lt[26]={};
    for (int i=0; i<n; ++i) {
        int& r=lt[int(s[i])-97];
        dp[i+1]=((dp[i]<<1)%MOD-(r?dp[r-1]:0)+MOD)%MOD;
        r=i+1;
    }
    cout << (dp[n]+MOD-1)%MOD;
}
