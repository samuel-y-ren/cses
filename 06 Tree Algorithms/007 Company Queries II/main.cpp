// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-24 08:21:22 PST

#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;
vector<int> adj[MAXN];
int d[MAXN];

void dfs(int u, int dp) {
    d[u]=dp;
    for (int i : adj[u]) dfs(i,dp+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    int p[20][n+1];
    p[0][0]=0;
    p[0][1]=0;
    for (int i=1; i<n; i++) {
        cin >> p[0][i+1];
        adj[p[0][i+1]].emplace_back(i+1);
    }
    dfs(1,0);
    for (int s=1; s<20; s++) for (int i=0; i<=n; i++) p[s][i]=p[s-1][p[s-1][i]];
    while (q--) {
        int a,b; cin >> a >> b;
        int df=d[a]-d[b];
        if (df<0) {
            swap(a,b);
            df=-df;
        }
        for (int i=19; i>=0; i--) if (df&(1<<i)) a=p[i][a];
        for (int i=19; i>=0; i--) if (p[i][a]!=p[i][b]) {
            a=p[i][a]; 
            b=p[i][b];
        }
        if (a==b) cout << a << '\n';
        else cout << p[0][a] << '\n';
    }
}
