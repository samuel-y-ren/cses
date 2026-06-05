// File: 3273.cpp
// Author: Samuel Ren
// Created: 2026-05-28 11:24:12 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "? 1" << endl;
    int n; cin >> n;
    int l = 1, r = n + 1;
    char c; cin >> c;
    int lc, mc, rc = (c == 'R');
    lc = rc;
    while (l < r-1) {
        int m = (l+r) / 2;
        cout << "? " << m << endl;
        cin >> c;
        mc = (c == 'R');
        if (((m^l)&1)^mc^lc) {
            r = m;
            rc = mc;
        }
        else {
            l = m;
            lc = mc;
        }
    }
    cout << "! " << l;
}
