// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-13 22:45:50 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int h[n+1]; for (int i=0; i<n; i++) cin >> h[i+1];
    vector<pair<int,int>> stk;
    stk.push_back({2000000000,n+1});
    int dp[n+2]={};
    int nt[n+1];
    int pv[n+1];
    for (int i=n; i; i--) {
        while (h[i]>=stk.back().first) stk.pop_back();
        nt[i]=stk.back().second;
        stk.push_back({h[i],i});
    }
    stk.clear();
    stk.push_back({2000000000,0});
    for (int i=1; i<=n; i++) {
        while (h[i]>=stk.back().first) stk.pop_back();
        pv[i]=stk.back().second;
        stk.push_back({h[i],i});
    }
    pair<int,int> sa[n];
    for (int i=0; i<n; i++) sa[i]={h[i+1],i+1};
    sort(sa,sa+n);
    for (auto i : sa) {
        int k = i.second;
        dp[nt[k]] = max(dp[nt[k]], dp[k]+1);
        dp[pv[k]] = max(dp[pv[k]], dp[k]+1);
    }
    cout << max(dp[0],dp[n]);
}
