// File: main.cpp
// Author: Samuel Ren
// Created: 2025-11-14 16:42:45 EST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    int x,a,b,c; cin >> x >> a >> b >> c;
    int xc=x, xo=x;
    ll s=x;
    for (int i=1; i<k; ++i) s^=(xc=((ll)a*xc+b)%c);
    ll r=s;
    if (k!=n) {
        r^=(s^=(xc=((ll)a*xc+b)%c)^xo);
        for (int i=k+1; i<n; ++i) r^=(s^=(xc=((ll)a*xc+b)%c)^(xo=((ll)a*xo+b)%c));
    }
    cout << r;
}