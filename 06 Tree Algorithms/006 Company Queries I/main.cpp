// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-24 08:21:22 PST
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    int p[20][n+1];
    p[0][0]=0;
    p[0][1]=0;
    for (int i=1; i<n; i++) cin >> p[0][i+1];
    for (int s=1; s<20; s++) for (int i=0; i<=n; i++) p[s][i]=p[s-1][p[s-1][i]];
    while (q--) {
        int x,k; cin >> x >> k;
        for (int i=0; i<20; i++) if (k&(1<<i)) x=p[i][x];
        if (x) cout << x << '\n';
        else cout << "-1\n";
    }
}