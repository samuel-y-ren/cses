// File: main.cpp
// Author: Samuel Ren
// Created: 2026-05-28 10:44:27 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    if (k == 2*n) {
        cout << "F " << n << "\nS " << n << endl;
        int a, b;
        cin >> a >> b;
        cout << "! " << min(a, b) << endl;
        return 0;
    }
    int l = max(0, k-n-1), r = min(n, k);
    while (l < r-1) {
        int m = (l + r) / 2;
        cout << "F " << m << "\nS " << k-m << endl;
        int a, b; cin >> a >> b;
        if (a > b) l = m;
        else r = m;
    }
    int a = 0;
    if (l < n) {
        cout << "F " << l+1 << endl;
        cin >> a;
    }
    int b = 0;
    if (l > k-n-1) {
        cout << "S " << k-l << endl;
        cin >> b;
    }
    cout << "! " << max(a, b) << endl;
}
