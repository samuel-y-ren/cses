// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-01 21:05:10 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int mn=1000001;
    int d[mn]={};
    for (int i=2; i<mn; ++i) if (!d[i]) for (int j=i; j<mn; j+=i) d[j]=i;
    for (int i=mn-1; i>1; --i) if (d[i]==i) for (int j=i; j<mn; j+=i) d[j]=i;
    int n; cin >> n;
    int xi[mn]={};
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        ++xi[x];
    }
    ll t=n*(n-1ll)/2;
    for (int i=2; i<mn; ++i) {
        int u=1;
        int x=i;
        while (d[x]) {
            if (d[x]==d[x/d[x]]) {
                u=0;
                break;
            }
            u=-u;
            x=x/d[x];
        }
        if (!u) continue;
        int ct=0;
        for (int j=i; j<mn; j+=i) ct+=xi[j];
        t+=u*ct*(ct-1ll)/2;
    }
    cout << t;
}
