// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-15 20:57:44 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    string a[n]; for (int i=0; i<n; i++) cin >> a[i];
    int ps[n+1][n+1];
    for (int i=0; i<=n; i++) ps[i][0]=ps[0][i]=0;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) ps[i+1][j+1]=ps[i+1][j]+ps[i][j+1]-ps[i][j]+(a[i][j]=='*');
    while (q--) {
        int y1,x1,y2,x2; cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--;
        cout << ps[y2][x2]-ps[y2][x1]-ps[y1][x2]+ps[y1][x1] << '\n';
    }
}
