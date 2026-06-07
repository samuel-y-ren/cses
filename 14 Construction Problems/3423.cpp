// File: 3423.cpp.cpp
// Author: Samuel Ren
// Created: 2026-06-06 22:32:36 EST

#include <bits/stdc++.h>
using namespace std;

const int mn = 200005;
bool s[200005]={};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i=2; i<=2*n; ++i) if (!s[i]) for (int j=2*i; j<=2*n; j+=i) s[j] = true;
    int p[n];
    int m = n;
    while (m) {
        int i;
        for (i=1; s[m+i]; ++i);
        for (int j=i-1; j<m; ++j) p[j] = m+i-j-1;
        m=i-1;
    }
    for (int i=1; i<=n; ++i) cout << i << ' ';
    cout << '\n';
    for (int i=0; i<n; ++i) cout << p[i] << ' ';
}
