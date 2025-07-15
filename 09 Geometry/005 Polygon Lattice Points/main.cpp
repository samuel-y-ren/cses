// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-09 20:10:45 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll x[n], y[n]; for (int i=0; i<n; ++i) cin >> x[i] >> y[i];
    ll a=x[n-1]*y[0]-y[n-1]*x[0];
    for (int i=1; i<n; ++i) a+=x[i-1]*y[i]-y[i-1]*x[i];
    a = abs(a);
    ll b = gcd(x[n-1]-x[0],y[n-1]-y[0]);
    for (int i=1; i<n; ++i) b+=gcd(x[i-1]-x[i],y[i-1]-y[i]);
    cout << (a+2-b)/2 << ' ' << b;
}
