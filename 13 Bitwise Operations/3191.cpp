// File: 3191.cpp
// Author: Samuel Ren
// Created: 2026-05-28 14:16:32 EST

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
    int res = 0;
    for (int i=29; i>=0; --i) if (!((res>>i)&1) && basis[i]) res ^= basis[i];
    cout << res;
}
