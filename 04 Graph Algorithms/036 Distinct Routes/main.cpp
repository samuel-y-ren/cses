// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-14 20:38:13 PST

#include <bits/stdc++.h>
using namespace std;

const int MAXN=505;
int n;

int cap[MAXN][MAXN], fl[MAXN][MAXN];
int ht[MAXN], exc[MAXN];
queue<int> q;

vector<int> adj[MAXN];
int an[MAXN], cv[MAXN];

void ps(int u, int v) {
    int d = min(cap[u][v]-fl[u][v],exc[u]);
    if (!d) return;
    fl[u][v]+=d;
    fl[v][u]-=d;
    exc[u]-=d;
    exc[v]+=d;
    if (exc[v]==d) {
        q.push(v);
    }
}

void rl(int u) {
    int h=MAXN;
    for (int v : adj[u]) if (cap[u][v]>fl[u][v] && ht[v]<h) h=ht[v];
    if (h<MAXN) ht[u]=h+1;
}

void dc(int u) {
    while (exc[u]) {
        if (cv[u]<an[u]) {
            int v=adj[u][cv[u]];
            if (cap[u][v]>fl[u][v] && ht[u]>ht[v]) ps(u,v);
            cv[u]++;
        }
        else {
            rl(u);
            cv[u]=0;
        }
    }
}

vector<int> pat;

void dfs(int u) {
    if (u==n) {
        pat.push_back(u);
        return;
    }
    for (int v : adj[u]) if (fl[u][v]>0) {
        fl[u][v]--;
        fl[v][u]++;
        pat.push_back(u);
        dfs(v);
        return;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin >> n >> m;
    while (m--) {
        int a,b; cin >> a >> b;
        cap[a][b]++;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) if (cap[i][j] || cap[j][i]) adj[i].push_back(j);
        an[i]=adj[i].size();
    }
    exc[1]=1000000000;
    for (int i=2; i<=n; i++) ps(1,i);
    ht[1]=n;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u>1 && u<n && ht[u]<n) dc(u);
    }
    for (int i=2; i<n; i++) if (exc[i]) q.push(i);
    while (q.size()) {
        short u = q.front();
        q.pop();
        if (u && u<n) dc(u);
    }
    int tot=0;
    for (int i=1; i<n; i++) tot += fl[i][n];
    cout << tot << '\n';
    while (tot--) {
        dfs(1);
        cout << pat.size() << '\n';
        for (int i : pat) cout << i << ' ';
        cout << '\n';
        pat.clear();
    }
}