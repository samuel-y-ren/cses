// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-31 12:04:32 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD=1000000007;
ll xp(int a, int b) {
    ll r=1;
    for (int i=32-__builtin_clz(b);i>=0;i--) {
        r=r*r%MOD;
        if (b&(1<<i)) r=r*a%MOD;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    pair<int,int> d[n];
    for (int i=0; i<n; ++i) cin >> d[i].first >> d[i].second;
    ll nd=1;
    ll sd=1;
    ll pd=1;
    ll pp[n+1]; pp[0]=1;
    for (int i=0; i<n; ++i) {
        nd=nd*(d[i].second+1)%MOD;
        pp[i+1]=pp[i]*(d[i].second+1)%(MOD-1);
        sd=sd*(xp(d[i].first,d[i].second+1)-1)%MOD*xp(d[i].first-1,MOD-2)%MOD;
    }
    ll sp=1;
    for (int i=n-1;i>=0;--i) {
        pd=pd*xp(d[i].first,(d[i].second*(d[i].second+1ll)/2)%(MOD-1) *pp[i]%(MOD-1) *sp%(MOD-1))%MOD;
        sp=sp*(d[i].second+1)%(MOD-1);
    }
    cout << nd << ' ' << sd << ' ' << pd;
}