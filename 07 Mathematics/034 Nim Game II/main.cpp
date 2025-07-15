// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-06 10:44:26 PST

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
            t^=x;
        }
        cout << (t&3 ? "first\n" : "second\n");
    }
}