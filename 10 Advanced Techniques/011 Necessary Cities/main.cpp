// File: main.cpp
// Author: Samuel Ren
// Created: 2025-09-05 12:28:50 PST

#include <bits/stdc++.h>
using namespace std;

const int mn=100005;
vector<int> a[mn];

int o[mn], t=0;
int s[mn];
int po[mn];

const int ml=18;
int bp[ml][mn];

void dfs1(int v) {
    o[v]=++t;
    for (auto i : a[v]) if (!o[i]) {
        bp[0][i]=v;
        dfs1(i);
        s[v]+=s[i];
    }
    ++s[v];
}

vector<pair<int,int>> cc[mn];

void lp() {
    for (int i=1; i<=n; ++i) po[i]=o[i]+s[i];
    po[0]=1000000000;
    for (int s=1; s<ml; ++s) for (int i=1; i<=n; ++i) bp[s][i]=bp[s-1][bp[s-1][i]];
    for (int i=1; i<=n; ++i) for (int j : a[i]) if (bp[0][i]!=j && bp[0][j]!=i) {
        int l,tg;
        if (o[i]<o[j]) l=i, tg=o[j];
        else l=j, tg=o[i];
        for (int s=ml-1; ~s; --s) if (po[bp[s][l]]<=tg) l=bp[s][l];
        if (po[l]<=tg) l=bp[0][l];
        if (l!=i && l!=j)
    }
}

bool nc[mn];
bool vs[mn];
pair<int,int> dfs2(int v, int p) {
    if (vs[v]) return(make_pair(o[v],o[v]));
    vs[v]=true;
    pair<int,int> m(o[v],0);
    for (auto i : a[v]) if (i!=p) {
        pair<int,int> rt=dfs2(i,v);
        m.first=min(m.first,rt.first);
        m.second=max(m.second,rt.second);
    }
    if (m.first>=o[v] && m.second<o[v]+s[v] && p) nc[v]=nc[p]=1;
    return m;
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
    dfs1(1);

    dfs2(1,0);
}
