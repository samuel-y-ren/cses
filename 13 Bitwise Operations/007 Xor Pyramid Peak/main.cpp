// File: main.cpp
// Author: Samuel Ren
// Created: 2026-05-29 15:35:08 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int v = 0;
    int res = 0;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        if (!v) res ^= x;
        v += __builtin_ctz(n-i-1) - __builtin_ctz(i+1);
    }
    cout << res;
}
