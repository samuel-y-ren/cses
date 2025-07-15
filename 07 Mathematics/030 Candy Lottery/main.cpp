// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-04 20:40:54 PST

#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

ld xp(ld v, int b) {
    ld r=1;
    for (int i=31-__builtin_clz(b); ~i; --i) {
        r=r*r;
        if (b&(1<<i)) r=r*v;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    ld v[k+1]={};
    for (int i=1; i<=k; ++i) v[i]=xp((ld)i/k,n);
    ld f=0;
    for (int i=0; i<k; ++i) f+=(i+1)*(v[i+1]-v[i]);
    if (f*1000000-int(f*1000000)-.5<.0001) {
        if (int(f*1000000)%2) f+=.0000000001;
    }
    cout << fixed << setprecision(6) << f;
}
