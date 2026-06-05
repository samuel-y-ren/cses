// File: main.cpp
// Author: Samuel Ren
// Created: 2026-06-05 14:15:05 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    int a[n];
    for (int i=0; i<n; ++i) cin >> a[i];
    int b = (n-k);
    for (int j=0; j<21; ++j) if ((b>>j) & 1) {
        int s = (1<<j);
        for (int i=0; i<n-s; ++i) a[i] ^= a[i+s];
        n -= s;
    }
    for (int i=0; i<n; ++i) cout << a[i] << ' ';
}
