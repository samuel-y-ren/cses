// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-24 18:10:54 PST

#include <bits/stdc++.h>
using namespace std;

inline int lg(int x) {
    return 31-__builtin_clz(x);
}

const int mn=200005;
int n;

vector<int> adj[mn];

int tin[mn];
int t;
int et[2*mn];
int dep[mn];

int stn[mn];
int par[mn];
int bc[mn];

vector<int> ds;

void dfs(int u, int p, int d) {
    ds.emplace_back(u);
    tin[u]=t;
    dep[u]=d;
    par[u]=p;
    for (int i : adj[u]) if (i != p) {
        et[t++]=u;
        dfs(i,u,d+1);
        stn[u]+=stn[i];
        if (stn[i]>stn[bc[u]]) bc[u]=i;
    }
    stn[u]++;
}

pair<int,int> sp[20][mn];

void spu() {
    for (int i=0; i<t; ++i) sp[0][i]={dep[et[i]],et[i]};
    for (int i=1; i<20; ++i) {
        const int ub=n-(1<<i)+1;
        for (int j=0; j<ub; ++j) sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
    }
}

int lca(int l, int r) {
    if (l==r) return l;
    l=tin[l]; r=tin[r];
    if (r<l) swap(l,r);
    int d = lg(r-l);
    return min(sp[d][l],sp[d][r-(1<<d)]).second;
}

int v[mn];

struct pt;
pt* ph[mn];
int pi[mn];

struct pt {
    vector<int> st;
    int n;
    void upd(int u, int x) {
        for (st[u+=n]=x;u>1;u>>=1) st[u>>1]=max(st[u],st[u^1]);
    }
    int qu(int l, int r) {
        int res=0;
        for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) res = max(res,st[l++]);
            if (r&1) res = max(res,st[--r]);
        }
        return res;
    }
    vector<int> nd;
    int upn;
    pt(int sn) {
        int cn=sn;
        int id=0;
        while (cn) {
            nd.emplace_back(cn);
            ph[cn]=this;
            pi[cn]=id++;
            cn=bc[cn];
        }
        n = nd.size();
        st.resize(2*n);
        for (int i=0; i<n; ++i) st[i+n]=v[nd[i]];
        for (int i=n-1; i>0; --i) st[i]=max(st[i<<1],st[(i<<1)|1]);
        upn=par[sn];
    }
};

int pq(int u, int l) {
    int res=0;
    while (ph[u]!=ph[l]) {
        res = max(res, (*ph[u]).qu(0,pi[u]+1));
        u=(*ph[u]).upn;
    }
    return max(res, (*ph[u]).qu(pi[l],pi[u]+1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<n; i++) {
        int a,b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1,0,0);
    spu();
    for (int i : ds) if (!ph[i]) new pt(i);
    while (q--) {
        int qt; cin >> qt;
        if (qt==1) {
            int s,x; cin >> s >> x;
            (*ph[s]).upd(pi[s],x);
        }
        else {
            int a,b; cin >> a >> b;
            int l = lca(a,b);
            cout << max(pq(a,l),pq(b,l)) << ' '; 
        }
    }
}
