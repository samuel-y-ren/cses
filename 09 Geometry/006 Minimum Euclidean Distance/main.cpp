// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-09 20:35:22 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=200005;

pair<ll,ll> p[MAXN];

inline ll d(pair<ll,ll>& a, pair<ll,ll>& b) {
    ll x=a.first-b.first, y=a.second-b.second;
    return x*x+y*y;
}

pair<ll,ll> v[MAXN];

int csq(ll x) {
    int c=INT_MAX^(1<<30);
    for (int i=30; i; c^=(1<<(--i))) if ((ll)c*c<x) c|=(1<<(i));
    if ((ll)c*c<x) c|=1;
    return c;
}

void smin(ll& a, const ll b) {
    if (b<a) a=b;
}

bool cp(const pair<ll,ll>& a, const pair<ll,ll>& b) {
    return a.second<b.second;
}

ll dq(int l, int r) {
    if (r==l+1) return 9000000000000000000ll;
    if (r==l+2) return d(p[l],p[l+1]);
    int m = (l+r)>>1;
    ll cd=min(dq(l,m),dq(m,r));
    int sd=csq(cd);
    int sz=0;
    for (int i=l; i<r; ++i) if (abs(p[m].first-p[i].first)<sd) v[sz++]=p[i];
    sort(v,v+sz,cp);
    for (int i=0; i<sz; ++i) for (int j=i+1; j<min(i+8,sz); ++j) smin(cd,d(v[i],v[j]));
    return cd;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i=0; i<n; ++i) cin >> p[i].first >> p[i].second;
    sort(p,p+n);
    cout << dq(0,n);
}
