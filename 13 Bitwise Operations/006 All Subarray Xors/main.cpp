// File: main.cpp
// Author: Samuel Ren
// Created: 2026-05-29 14:55:39 EST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mx=1<<20;
ll a[mx]={};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int px = 0;
    ll m = 1;
    ++a[0];
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        m = max(m, ++a[px ^= x]);
    }
    for (int b=1; b<21; ++b) {
        for (int i=0, s=(1<<(b-1)); i < mx; i+=(1<<b)) {
            for (int j=0; j<s; ++j) {
                ll x = a[i+j], y = a[s+i+j];
                a[i+j] = x + y;
                a[s+i+j] = x - y;
            }
        }
    }
    for (int i=0; i<mx; ++i) a[i] *= a[i];
    for (int b=1; b<21; ++b) {
        for (int i=0, s=(1<<(b-1)); i < mx; i+=(1<<b)) {
            for (int j=0; j<s; ++j) {
                ll x = a[i+j], y = a[s+i+j];
                a[i+j] = (x + y) / 2;
                a[s+i+j] = (x - y) / 2;
            }
        }
    }
    int res = (m > 1);
    for (int i=1; i<mx; ++i) if (a[i]>0) ++res;
    cout << res << '\n';
    if (m > 1) cout << "0 ";
    for (int i=1; i<mx; ++i) if (a[i]>0) cout << i << ' ';
}
