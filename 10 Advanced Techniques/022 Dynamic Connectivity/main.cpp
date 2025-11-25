// File: main.cpp
// Author: Samuel Ren
// Created: 2025-11-04 11:05:20 PST

#include <bits/stdc++.h>
using namespace std;

const int mn=100005;
pair<int,int> nd[mn];
vector<pair<int,int>> ol;
int ns;

inline int par(int u) {
    while (nd[u].first != u) u=nd[u].first;
    return u;
}

void merge(int u, int v) {
    u=par(u); v=par(v);
    if (u==v) return;
    if (nd[u].second>nd[v].second) swap(u,v);
    ol.emplace_back(u,v);
    --ns;
    nd[u].first=v;
    nd[v].second+=nd[u].first;
}

inline void rb() {
    int u=ol.back().first;
    int v=ol.back().second;
    ol.pop_back();
    ++ns;
    nd[u].first=u;
    nd[v].second-=nd[u].second;
}

vector<pair<int,int>> e[mn*4];

int tin,tout,nu,nv;
void ins(int i, int l, int r) {
    if (r<=tin || tout<=l) return;
    if (tin <= l && r <= tout) {
        e[i].emplace_back(nu,nv);
        return;
    }
    int m=(l+r)/2;
    ins(2*i,l,m);
    ins(2*i+1,m,r);
}

void dfs(int i, int l, int r) {
    int ss=ol.size();
    for (const auto& j : e[i]) {
        merge(j.first,j.second);
    }
    ss=ol.size()-ss;
    if (l+1==r) cout << ns << ' ';
    else {
        int m = (l+r)/2;
        dfs(2*i,l,m);
        dfs(2*i+1,m,r);
    }
    while (ss--) rb();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k; cin >> n >> m >> k;
    ns=n;
    for (int i=1; i<=n; ++i) nd[i]={i, 1};
    map<pair<int,int>, int> cl;
    vector<pair<pair<int,int>,pair<int,int>>> sg;
    while (m--) {
        int u,v; cin >> u >> v;
        if (u>v) swap(u,v);
        cl[make_pair(u,v)]=0;
    }
    for (int i=1; i<=k; ++i) {
        int t,u,v; cin >> t >> u >> v;
        if (u>v) swap(u,v);
        if (t==1) cl[make_pair(u,v)]=i;
        else {
            auto ptr=cl.find(make_pair(u,v));
            sg.emplace_back(make_pair(u,v),make_pair((*ptr).second,i));
            cl.erase(ptr);
        }
    }
    for (const auto& i : cl) sg.emplace_back(i.first,make_pair(i.second,k+1));
    for (const auto& i : sg) {
        tin=i.second.first;
        tout=i.second.second;
        nu=i.first.first;
        nv=i.first.second;
        ins(1,0,k+1);
    }
    dfs(1,0,k+1);
}
