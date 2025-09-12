// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-15 10:34:29 PST
 
#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 50005;
vector<int> f[MAXN],r[MAXN];
int v[MAXN];
int po[MAXN], t=0;
 
void dfs1(int c) {
    if (v[c]) return;
    v[c]=1;
    for (int j : f[c]) dfs1(j);
    po[t++]=c;
}
 
void dfs2(int c, int s) {
    if (v[c]) return;
    v[c]=s;
    for (int j : r[c]) dfs2(j,s);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,qn; cin >> n >> m >> qn;
    while (m--) {
        int a,b; cin >> a >> b;
        f[a].emplace_back(b);
        r[b].emplace_back(a);
    }
    for (int i=1; i<=n; ++i) dfs1(i);
    for (int i=1; i<=n; ++i) v[i]=0;
    for (int i=n-1; ~i; --i) dfs2(po[i],po[i]);
    set<int> rs[n+1];
    int no[n+1]={};
    for (int i=1; i<n; ++i) for (int j : r[i]) {
        if (v[i]!=v[j]&&rs[v[i]].find(v[j])==rs[v[i]].end()) {
            ++no[v[j]];
            rs[v[i]].insert(v[j]);
        }
    }
    bitset<50001> dp[n+1]={};
    queue<int> q;
    for (int i=1; i<=n; ++i) if (!no[i]&&v[i]==i) q.push(i);
    while (q.size()) {
        int c = q.front();
        q.pop();
        dp[c][c]=1;
        for (int i : rs[c]) {
            dp[i]|=dp[c];
            if (!(--no[i])) q.push(i);
        }
    }
    while (qn--) {
        int a,b; cin >> a >> b;
        cout << (dp[v[a]][v[b]] ? "YES\n" : "NO\n");
    }
}