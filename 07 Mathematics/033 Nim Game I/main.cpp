// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-05 15:17:30 PST

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
        cout << (t ? "first\n" : "second\n");
    }
}
