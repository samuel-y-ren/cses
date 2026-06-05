// File: 1146.cpp
// Author: Samuel Ren
// Created: 2026-05-28 12:44:58 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    long long tot = 0;
    for (int i=60; i>=0; --i) {
        tot += (n>>(i+1)) * (1ll<<i);
        if ((n>>i) & 1) {
            tot += (n & ((1ll<<i) - 1)) + 1;
        }
    }
    cout << tot << '\n';
}
