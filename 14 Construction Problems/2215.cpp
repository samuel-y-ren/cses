// File: 2215.cpp
// Author: Samuel Ren
// Created: 2026-06-06 21:43:07 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n,k; cin >> n >> k;
        if (k*k < n) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for (int i=k; i>0; --i) for (int j=i; j<=n; j+=k) cout << j << ' ';
        cout << '\n';
    }
}
