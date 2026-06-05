// File: main.cpp
// Author: Samuel Ren
// Created: 2025-09-05 12:28:50 PST

#include <bits/stdc++.h>
using namespace std;

const int mn=100005;
vector<int> a[mn];
bool ans[mn];
int ti[mn]; int t;
int l[mn];

void dfs(int v, int p) {
    l[v]=ti[v]=++t;
    int cc=0;
    for (int i : a[v]) if (i!=p) {
        if (ti[i]) l[v]=min(l[v],ti[i]);
        else {
            dfs(i,v);
            l[v]=min(l[v],l[i]);
            if (l[i]>=ti[v] && p) ans[v]=1;
            ++cc;
        }
    }
    if (!p && cc>1) ans[1]=1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    while (m--) {
        int u,v; cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    dfs(1,0);
    int tt=0; for (int i=1; i<=n; ++i) tt+=ans[i];
    cout << tt << '\n';
    for (int i=1; i<=n; ++i) if (ans[i]) cout << i << ' ';
}
