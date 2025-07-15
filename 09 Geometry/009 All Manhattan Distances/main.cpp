// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-11 15:10:33 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    assert(scanf("%d",&n));
    int x[n], y[n]; for (int i=0; i<n; ++i) assert(scanf("%d %d",&x[i], &y[i]));
    sort(x,x+n); sort(y,y+n);
    int ex=0;
    ll td=0;
    ll ts=0;
    for (int i=0; i<n; ++i) {
        td += (ll)i*x[i]-ts;
        ts += x[i];
        if (td>=1000000000000000000) {
            td-=1000000000000000000;
            ++ex;
        }
    }
    ts=0;
    for (int i=0; i<n; ++i) {
        td += (ll)i*y[i]-ts;
        ts += y[i];
        if (td>=1000000000000000000) {
            td-=1000000000000000000;
            ++ex;
        }
    }
    if (ex) {
        printf("%d",ex);
        printf("%018lld",td);
    }
    else printf("%lld",td);
}
