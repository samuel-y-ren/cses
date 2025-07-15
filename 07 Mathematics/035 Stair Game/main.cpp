// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-06 11:24:36 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int t=0;
        for (int i=0; i<n; ++i) {
            int x; cin >> x;
            if (i&1) t^=x;
        }
        cout << (t ? "first\n" : "second\n");
    }
}