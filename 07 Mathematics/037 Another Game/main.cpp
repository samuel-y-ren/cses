// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-06 11:52:09 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool w=0;
        for (int i=0; i<n; ++i) {
            int x; cin >> x;
            w|=x&1;
        }
        cout << (w ? "first\n" : "second\n");
    }
}
