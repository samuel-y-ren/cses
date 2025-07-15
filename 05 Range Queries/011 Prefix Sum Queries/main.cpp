// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-15 22:40:12 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=200005;

ll ps[MAXN];
ll st[MAXN*4];
ll t[MAXN*4];

void pus(int u) {
    if (!t[u]) return;
    if (u<2*MAXN-1) {
        t[2*u]+=t[u];
        t[2*u+1]+=t[u];
    }
    st[u]+=t[u];
    t[u]=0;
}

void ini(int u, int l, int r) {
    if (l+1==r) {
        st[u]=ps[l];
        return;
    }
    const int m = (l+r+1)/2;
    ini(2*u,l,m);
    ini(2*u+1,m,r);
    st[u]=max(st[2*u],st[2*u+1]);
}

void upd(int u, int l, int r, int ul, int v) {
    if (r<=ul) return;
    if (ul<=l) {
        t[u]+=v;
        return;
    }
    const int m = (l+r+1)/2;
    upd(2*u,l,m,ul,v);
    upd(2*u+1,m,r,ul,v);
    st[u]=max(st[2*u]+t[2*u],st[2*u+1]+t[2*u+1]);
}

ll qu(int u, int l, int r, int ql, int qr) {
    if (qr<=l || r<=ql) return -1000000000000000000;
    pus(u);
    if (ql<=l && r<=qr) return st[u];
    const int m = (l+r+1)/2;
    return max(qu(2*u,l,m,ql,qr), qu(2*u+1,m,r,ql,qr));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    int x[n]; for (int i=0; i<n; i++) cin >> x[i];
    ps[0]=x[0];
    for (int i=1; i<n; i++) ps[i]=ps[i-1]+x[i];
    ini(1,0,n);
    while (q--) {
        int qt; cin >> qt;
        if (qt==1) {
            int k,u; cin >> k >> u;
            k--;
            upd(1,0,n,k,u-x[k]);
            x[k]=u;
        }
        else {
            int a,b; cin >> a >> b;
            if (a==1) cout << max(qu(1,0,n,0,b),0ll) << '\n';
            else cout << qu(1,0,n,a-2,b)-qu(1,0,n,a-2,a-1) << '\n';
        }
    }
}
