// File: main.cpp
// Author: Samuel Ren
// Created: 2025-09-14 17:56:51 PST

#include <bits/stdc++.h>
using namespace std;

const int mn=100005;
vector<int> a[mn];
bool vs[mn];
int tot;

void dfs(int v, int p) {
    vs[v]=1;
    for (int i : a[v]) if (i!=p) {
        if (vs[i]) ++tot;
        else dfs(i, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    while (m--) {
        int u,v; cin >> u >> v;
        a[u].emplace_back(v); a[v].emplace_back(u);
    }
    for (int i=1; i<=n; ++i) if (!vs[i]) dfs(i, 0);
    int ans=1; tot/=2;
    while (tot--) ans=(ans*2)%1000000007;
    cout << ans;
}
