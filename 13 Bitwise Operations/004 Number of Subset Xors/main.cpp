// File: main.cpp
// Author: Samuel Ren
// Created: 2026-05-28 14:23:25 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int basis[30] = {};
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        for (int i=29; i>=0; --i) {
            if ((x>>i)&1) {
                if (basis[i]) x ^= basis[i];
                else {
                    basis[i] = x;
                    break;
                }
            }
        }
    }
    int res = 1;
    for (int i=29; i>=0; --i) if (basis[i]) res <<= 1;
    cout << res;
}
