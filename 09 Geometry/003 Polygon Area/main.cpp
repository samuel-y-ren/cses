// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-09 19:30:39 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll x[n], y[n]; for (int i=0; i<n; ++i) cin >> x[i] >> y[i];
    ll t=x[n-1]*y[0]-y[n-1]*x[0];
    for (int i=1; i<n; ++i) t+=x[i-1]*y[i]-y[i-1]*x[i];
    cout << abs(t);
}
