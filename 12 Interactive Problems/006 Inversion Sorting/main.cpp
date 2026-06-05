// File: main.cpp
// Author: Samuel Ren
// Created: 2026-05-28 11:32:34 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    cout << "1 " << n << endl;
    int r1, r2;
    cin >> r1;
    if (!r1) return 0;
    for (int i=1; i<n; ++i) {
        cout << "1 " << i+1 << endl;
        cin >> r1;
        if (!r1) break;
        cout << "1 " << i+1 << endl;
        cin >> r2;
        int d = r1 - (i * (i-1)) / 2 - r2;
        int idx = (d + i) / 2;
        if (idx < i) {
            cout << idx+1 << ' ' << i+1 << endl;
            cin >> r1;
            if (!r1) break;
            if (idx+2 < i+1) {
                cout << idx+2 << ' ' << i+1 << endl;
                cin >> r1;
                if (!r1) break;
            }
        }
    }
}
