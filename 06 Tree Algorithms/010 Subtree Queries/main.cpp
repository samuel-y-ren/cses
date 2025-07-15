// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-24 09:27:16 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mn = 200005;
int n;

ll st[2*mn];
int tv[mn];

void ini() {
    for (int i=0; i<n; ++i) st[i+n]=tv[i];
    for (int i=n-1; i>0; --i) st[i]=st[i<<1]+st[(i<<1)|1];
}

void upd(int id, int x) {
    for (st[id+=n]=x; id>1; id>>=1) st[id>>1] = st[id]+st[id^1];
}

ll qu(int l, int r) {
    ll res=0;
    for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
        if (l&1) res+=st[l++];
        if (r&1) res+=st[--r];
    }
    return res;
}

vector<int> adj[mn];

int tin[mn], tout[mn];
int ct;
void dfs(int u, int p) {
    tin[u]=ct++;
    for (int i : adj[u]) if (i!=p) dfs(i,u);
    tout[u]=ct;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> n >> q;
    int v[n+1]; for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<n; i++) {
        int a,b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1,0);
    for (int i=1; i<=n; i++) tv[tin[i]]=v[i];
    ini();
    while (q--) {
        int qt; cin >> qt;
        if (qt==1) {
            int s,x; cin >> s >> x;
            upd(tin[s],x);
        } else {
            int s; cin >> s;
            cout << qu(tin[s], tout[s]) << '\n';
        }
    }
}
