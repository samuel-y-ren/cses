// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-20 19:01:34 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    bool g[n][n];
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<n; j++) g[i][j] = s[j]=='*';
    }
    int ps[n][n+1];
    for (int i=0; i<n; i++) {
        ps[i][0]=0;
        for (int j=0; j<n; j++) ps[i][j+1] = ps[i][j]+g[i][j];
    }
    while (q--) {
        int qt; cin >> qt;
        if (qt==1) {
            int y,x; cin >> y >> x;
            --y; --x;
            g[y][x] = !g[y][x];
            if (g[y][x]) while (x<n) ++ps[y][++x];
            else while (x<n) --ps[y][++x];
        }
        else {
            int y1,x1,y2,x2; cin >> y1 >> x1 >> y2 >> x2;
            --x1;
            int tot=0;
            for (int i=y1-1; i<y2; ++i) tot+=ps[i][x2]-ps[i][x1];
            cout << tot << '\n';
        }
    }
}
