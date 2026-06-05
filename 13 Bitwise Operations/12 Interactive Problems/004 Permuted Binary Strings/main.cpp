// File: main.cpp
// Author: Samuel Ren
// Created: 2026-05-28 11:13:21 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int k = 32 - __builtin_clz(n-1);
    for (int i=k-1; i>=0; --i) {
        cout << "? ";
        for (int j=0; j<n; ++j) cout << ((j>>i) & 1);
        cout << '\n';
    }
    cout.flush();
    int p[n] = {};
    for (int i=k-1; i>=0; --i) {
        string s; cin >> s;
        for (int j=0; j<n; ++j) p[j] += (s[j]=='1' ? (1<<i) : 0);
    }
    cout << "! ";
    for (int i : p) cout << i+1 << ' ';
}
