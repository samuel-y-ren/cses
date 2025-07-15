// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-01 20:50:51 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int lg(ll x) {
    return 64-__builtin_clzll(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; int k; cin >> n >> k;
    ll a[k]; for (int i=0; i<k; ++i) cin >> a[i];
    ll t=0;
    const int ub=1<<k;
    for (int i=1; i<ub; i++) {
        ll d=1;
        bool w=true;
        for (int j=0; j<k; j++) if (i&(1<<j)) {
            if (lg(d)+lg(a[j])>61||d*a[j]>n) {
                w=false;
                break;
            }
            d*=a[j];
        }
        if (w) t+=(__builtin_popcount(i)&1?1:-1) * (n/d);
    }
    cout << t;
}
