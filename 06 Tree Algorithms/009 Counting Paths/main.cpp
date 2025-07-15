// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-24 08:58:33 PST

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXL = 20;

vector<int> adj[MAXN];
int p[MAXL][MAXN], np[MAXL][MAXN];
int d[MAXN];

void dfs(int u, int pr, int dp) {
    p[0][u]=pr;
    d[u]=dp;
    for (int i : adj[u]) if (i!=pr) dfs(i,u,dp+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    for (int i=0; i<n-1; i++) {
        int a,b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1,0,0);
    for (int i=1; i<MAXL; i++) for (int j=1; j<=n; j++) p[i][j]=p[i-1][p[i-1][j]];
    while (m--) {
        int a,b; cin >> a >> b;
        if (d[a]<d[b]) swap(a,b);
        int ds=d[a]-d[b];
        for (int i=0; i<20; i++) if (ds&(1<<i)) {
            np[i][a]++;
            a=p[i][a];
        }
        if (a==b) {
            np[0][a]++;
            continue;
        }
        for (int i=19; i>=0; i--) if (p[i][a]!=p[i][b]) {
            np[i][a]++;
            a=p[i][a];
            np[i][b]++;
            b=p[i][b];
        }
        np[1][a]++;
        np[0][b]++;
    }
    for (int i=19; i>0; i--) for (int j=1; j<=n; j++) {
        np[i-1][j]+=np[i][j];
        np[i-1][p[i-1][j]]+=np[i][j];
    }
    for (int i=1; i<=n; i++) cout << np[0][i] << ' ';
    cout << '\n';
}
