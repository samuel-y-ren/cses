// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-14 19:46:39 PST
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x; cin >> n >> x;
    int m=n>>1; n-=m;
    int t1[n], t2[m];
    for (int i=0; i<n; ++i) cin >> t1[i];
    for (int i=0; i<m; ++i) cin >> t2[i];
    int k=(1<<n), l=(1<<m);
    int s[k]; s[0]=0;
    for (int i=1; i<k; ++i) {
        int h=31-__builtin_clz(i);
        s[i]=min(s[i^(1<<h)]+t1[h],1000000001);
    }
    sort(s,s+k);
    int p[l]; p[0]=0;
    for (int i=1; i<l; ++i) {
        int h=31-__builtin_clz(i);
        p[i]=min(p[i^(1<<h)]+t2[h],1000000001);
    }
    ll t=0;
    for (int i : p) t+=upper_bound(s,s+k,x-i)-lower_bound(s,s+k,x-i);
    cout << t;
}