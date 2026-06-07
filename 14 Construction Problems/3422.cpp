// File: 3422.cpp
// Author: Samuel Ren
// Created: 2026-06-06 22:12:40 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    if (n==2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int a[n], b[n];
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<n; ++i) cin >> b[i];
    for (int i=0; i<n; ++i) {
        --a[i];
        --b[i];
    }
    int c[n];
    for (int i=0; i<n; ++i) {
        c[a[i]] = b[i];
    }
    for (int i=0; i<n; ++i) b[i] = -1;
    vector<pair<int,int>> ex;
    for (int i=0; i<n; ++i) {
        if (c[c[i]] == i) {
            if (c[i] > i) ex.emplace_back(i, c[i]);
        } else {
            b[c[i]] = i;
        }
    }
    int s = (int) ex.size();
    if (s == 1) {
        bool st = false;
        for (int i=0; i<n; ++i) {
            if (b[i] != -1) {
                if (!st) {
                    st = true;
                    b[ex[0].first] = b[i];
                    b[i] = ex[0].first;
                } else {
                    b[ex[0].second] = b[i];
                    b[i] = ex[0].second;
                    break;
                }
            }
        }
    } else if (s > 0) {
        for (int i=0; i<s-1; ++i) b[ex[i].first] = ex[i+1].first;
        b[ex[s-1].first] = ex[0].second;
        for (int i=0; i<s-1; ++i) b[ex[i].second] = ex[i+1].second;
        b[ex[s-1].second] = ex[0].first;
    }
    for (int i=0; i<n; ++i) c[i] = b[a[i]];
    for (int i=0; i<n; ++i) cout << c[i]+1 << ' ';
}
