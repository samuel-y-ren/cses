// File: main.cpp
// Author: Samuel Ren
// Created: 2025-10-31 16:14:49 EST

#include <bits/stdc++.h>
using namespace std;

const int mn=200005;
pair<int,int> par[mn];
int sz[mn];
int t;

inline int root(int u) {
    while (par[u].first != u) u=par[u].first;
    return u;
}

void merge(int u, int v) {
    u=root(u); v=root(v);
    if (u==v) return;
    if (sz[u]>sz[v]) swap(u,v);
    sz[v]+=sz[u];
    par[u]={v,t};
}

int lq(int u, int v) {
    int mt=0;
    while (u != v) {
        if (par[u].second>t && par[v].second>t) return -1;
        else if (par[u].second < par[v].second) {
            mt=par[u].second;
            u=par[u].first;
        }
        else {
            mt=par[v].second;
            v=par[v].first;
        }
    }
    return mt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q; cin >> n >> m >> q;
    for (int i=0; i<=n; ++i) {
        par[i]={i,1000000000};
        sz[i]=1;
    }
    for (int i=0; i<m; ++i) {
        ++t;
        int a,b; cin >> a >> b;
        merge(a,b);
    }
    while (q--) {
        int a,b; cin >> a >> b;
        cout << lq(a,b) << '\n';
    }
}
