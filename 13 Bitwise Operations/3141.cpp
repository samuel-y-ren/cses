// File: 3141.cpp
// Author: Samuel Ren
// Created: 2026-06-05 14:31:12 EST

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int b = 32 - __builtin_clz(n);
    int m = 1<<b;
    int a[m]={};
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        ++a[x];
    }
    for (int i=0; i<b; ++i) {
        int s = (1<<i);
        for (int j=0; j<m; j+=(2<<i)) {
            for (int k=0; k<s; ++k) {
                a[j+k] += a[s+j+k];
            }
        }
    }
    
    int p2[m+1];
    p2[0]=1;
    for (int i=0; i<m; ++i) p2[i+1] = (p2[i]<<1)%MOD;
    for (int i=0; i<m; ++i) a[i] = p2[a[i]];
    for (int i=0; i<b; ++i) {
        int s = (1<<i);
        for (int j=0; j<m; j+=(2<<i)) {
            for (int k=0; k<s; ++k) {
                a[j+k] = (a[j+k] + MOD - a[s+j+k])%MOD;
            }
        }
    }
    for (int i=0; i<=n; ++i) {
        cout << a[i]%MOD << ' ';
    }
}
