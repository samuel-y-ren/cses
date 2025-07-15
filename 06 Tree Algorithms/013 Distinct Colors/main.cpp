// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-25 17:00:14 PST

#include <bits/stdc++.h>
using namespace std;

const int mn=200005;

set<int> c[mn];

vector<int> adj[mn];
int ans[mn];

void dfs(int u, int p) {
    for (int i : adj[u]) if (i!=p) {
        dfs(i,u);
        if (c[i].size()>c[u].size()) swap(c[i], c[u]);
    }
    for (int i : adj[u]) if (i!=p) for (auto i : c[i]) c[u].insert(i);
    ans[u] = c[u].size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        int tc; cin >> tc;
        c[i].insert(tc);
    }
    for (int i=0; i<n-1; i++) {
        int a,b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1,0);
    for (int i=1; i<=n; i++) cout << ans[i] << ' ';
}
