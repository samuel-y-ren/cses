// File: 3194.cpp
// Author: Samuel Ren
// Created: 2026-06-05 14:08:26 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int a[n];
    for (int i=0; i<n; ++i) cin >> a[i];
    int m = 32 - __builtin_clz(n);
    for (int i = 0; i < m; ++i) {
        int b = (1<<i);
        for (int j=0; j<n; j += (2<<i)) {
            for (int k=0; j+b+k<n && k<b; ++k) {
                a[j+k+b] ^= a[j+k];
            }
        }
    }
    for (int i=0; i<n; ++i) cout << a[i] << ' ';
}
