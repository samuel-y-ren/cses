// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-25 17:06:41 PST

#include <bits/stdc++.h>
using namespace std;

const int mn=200005;

vector<int> adj[mn];
int ss[mn];
int n;

int ans;

void dfs(int u, int p) {
    bool f = true;
    for (int i : adj[u]) if (i!=p) {
        dfs(i,u);
        ss[u]+=ss[i];
        f&=(ss[i]<=n/2);
    }
    ss[u]++;
    if (f && ss[u]>=(n+1)/2) ans=u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a,b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1,0);
    cout << ans;
}
