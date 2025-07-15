// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-14 07:48:43 PST

#include <bits/stdc++.h>
using namespace std;

const int MAXN=505;

int v[MAXN];
int c;
vector<int> a[MAXN];
int p[MAXN];

bool dfs(int u) {
    if (u==-1) return true;
    if (v[u]==c) return false;
    v[u]=c;
    for (int i : a[u]) if (dfs(p[i])) {
        p[i]=u;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k; cin >> n >> m >> k;
    for (int i=1; i<=m; i++) p[i]=-1;
    while (k--) {
        int x,y; cin >> x >> y;
        a[x].push_back(y);
    }
    int tot = 0;
    for (int i=1; i<=n; i++) {
        c=i;
        if (dfs(i)) tot++;
    }
    cout << tot << '\n';
    for (int i=1; i<=m; i++) if (p[i] != -1) cout << p[i] << ' ' << i << '\n';
}
