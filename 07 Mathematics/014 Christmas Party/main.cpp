// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-02 18:55:05 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int MOD=1000000007;
    int n; cin >> n;
    long long d[n+1];
    d[0]=1; d[1]=0;
    for (int i=2; i<=n; ++i) d[i]=(i-1)*(d[i-1]+d[i-2])%MOD;
    cout << d[n];
}
