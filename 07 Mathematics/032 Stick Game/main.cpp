// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-05 15:13:40 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    int p[k]; for (int i=0; i<k; ++i) cin >> p[i];
    bool w[n+1];
    w[0]=false;
    for (int i=1; i<=n; ++i) {
        w[i]=false;
        for (int j : p) if (j<=i&&!w[i-j]) {
            w[i]=true;
            break;
        }
    }
    for (int i=1; i<=n; ++i) cout << (w[i] ? 'W' : 'L');
}
