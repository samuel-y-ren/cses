// File: main.cpp
// Author: Samuel Ren
// Created: 2025-09-05 11:59:38 PST

#include <bits/stdc++.h>
using namespace std;

const int mn=100005;
vector<int> a[mn];

int o[mn], t=0;
int s[mn];
void dfs1(int v) {
    o[v]=++t;
    for (auto i : a[v]) if (!o[i]) {
        dfs1(i);
        s[v]+=s[i];
    }
    ++s[v];
}

vector<pair<int,int>> r;
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
    if (m.first>=o[v] && m.second<o[v]+s[v]) r.emplace_back(v,p);
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
    int k=r.size();
    cout << --k << '\n';
    for (int i=0; i<k; ++i) cout << r[i].first << ' ' << r[i].second << '\n';
}
