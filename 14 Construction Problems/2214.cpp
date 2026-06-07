// File: 2214.cpp
// Author: Samuel Ren
// Created: 2026-06-06 21:34:56 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long k;
    cin >> n >> k;
    int p[n];
    int l = 0, r = n;
    for (int i=n-1; i>=0; --i) {
        if (k >= i) {
            k -= i;
            p[l++] = i+1;
        } else {
            p[--r] = i+1;
        }
    }
    for (int i=0; i<n; ++i) cout << p[i] << ' ';
}
