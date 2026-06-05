// File: main.cpp
// Author: Samuel Ren
// Created: 2026-05-29 10:29:41 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int basis[30] = {};
    int n, k; cin >> n >> k;
    for (int j=0; j<n; ++j) {
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
    int b = 0;
    for (int i=0; i<30; ++i) if (basis[i]) ++b;
    int m = (n-b < 32 ? ((k-1) >> (n-b)) : 0);
    int nb = (m ? (32 - __builtin_clz(m)) : 0);
    int bs = 1<<nb;
    int a[bs] = {};
    if (nb) for (int i=0; i<30; ++i) if (basis[i]) {
        --nb;
        for (int j=0; j<bs; j += 1<<(nb+1)) for (int l=0; l<(1<<nb); ++l) a[j+l] ^= basis[i];
        if (!nb) break;
    }
    sort(a, a+bs);
    m = (n-b < 32 ? (k >> (n-b)) : 0);
    for (int i=0; i<m; ++i) {
        for (int j=0; j<(1<<(n-b)); ++j) cout << a[i] << ' ';
    }
    if (m == 0) for (int i=0; i<k; ++i) cout << a[0] << ' ';
    else for (int i=0; i<(k&((1<<(n-b))-1)); ++i) cout << a[m] << ' ';

}
