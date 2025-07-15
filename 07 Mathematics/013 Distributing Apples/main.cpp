// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-01 22:00:56 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD=1000000007;
const int mn=2000000;

int xp(int a, int b) {
    ll r=1;
    for (int i=32-__builtin_clz(b); i>=0; --i) {
        r=r*r%MOD;
        if (b&(1<<i)) r=r*a%MOD;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll f[mn+1], fi[mn+1];
    f[0]=1;
    for (int i=1; i<=mn; ++i) f[i]=f[i-1]*i%MOD;
    fi[mn]=xp(f[mn],MOD-2);
    for (int i=mn; i>0; --i) fi[i-1]=fi[i]*i%MOD;
    int n,m; cin >> n >> m;
    cout << f[n+m-1]*fi[n-1]%MOD*fi[m]%MOD;
}