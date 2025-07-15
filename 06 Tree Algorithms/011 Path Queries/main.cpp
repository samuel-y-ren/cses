// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-24 10:01:05 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mn=200005;
int n;

ll st[2*mn];
ll tv[mn];

void ini() {
    for (int i=0; i<n; i++) st[i+n]=tv[i];
}

void upd(int l, int r, int v) {
    for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
        if (l&1) st[l++]+=v;
        if (r&1) st[--r]+=v;
    }
}

ll qu(int x) {
    ll res=0;
    for (x+=n; x>0; x>>=1) res+=st[x];
    return res;
}

vector<int> adj[mn];

int tin[mn], tout[mn];
int ct;
int v[mn];

void dfs(int u, int p, ll t) {
    t+=v[u];
    tv[ct]=t;
    tin[u]=ct++;
    for (int i : adj[u]) if (i!=p) dfs(i,u,t);
    tout[u]=ct;
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
    ini();
    while (q--) {
        int qt; cin >> qt;
        if (qt==1) {
            int s,x; cin >> s >> x;
            upd(tin[s],tout[s],x-v[s]);
            v[s]=x;
        }
        else {
            int s; cin >> s;
            cout << qu(tin[s]) << '\n';
        }
    }
}
