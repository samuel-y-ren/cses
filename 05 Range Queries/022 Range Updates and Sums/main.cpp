// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-20 21:04:21 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;
int x[MAXN];

struct nd {
    ll s,t,i;
};

nd st[MAXN*4];

void ini(int u, int l, int r) {
    if (l+1==r) {
        st[u].s=x[l];
        return;
    }
    const int m = (l+r+1)/2;
    ini(2*u,l,m);
    ini(2*u+1,m,r);
    st[u].s=st[2*u].s+st[2*u+1].s;
    return;
}

void ps(int u, int l, int r) {
    if (!st[u].t && !st[u].i) return;
    if (l+1<r) {
        const int m = (l+r+1)/2;
        if (st[u].t) {
            st[2*u]={(m-l)*st[u].t,st[u].t,0};
            st[2*u+1]={(r-m)*st[u].t,st[u].t,0};
        }
        if (st[u].i) {
            st[2*u].s += (m-l)*st[u].i;
            st[2*u].i += st[u].i;
            st[2*u+1].s += (r-m)*st[u].i;
            st[2*u+1].i += st[u].i;
        }
    }
    st[u].t=0; st[u].i=0;
}

void upd(int u, int l, int r, int ul, int ur, int k, bool t) {
    if (r<=ul || ur<=l) return;
    ps(u,l,r);
    if (ul<=l && r<=ur) {
        if (t) st[u]={(ll)(r-l)*k,k,0};
        else {
            st[u].s+=(ll)(r-l)*k;
            st[u].i+=k;
        }
        return;
    }
    const int m = (l+r+1)/2;
    upd(2*u,l,m,ul,ur,k,t);
    upd(2*u+1,m,r,ul,ur,k,t);
    st[u].s = st[2*u].s+st[2*u+1].s;
}

ll qu(int u, int l, int r, int ql, int qr) {
    if (r<=ql || qr<=l) return 0;
    if (ql<=l && r<=qr) return st[u].s;
    ps(u,l,r);
    const int m = (l+r+1)/2;
    return qu(2*u,l,m,ql,qr) + qu(2*u+1,m,r,ql,qr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    for (int i=0; i<n; i++) cin >> x[i];
    ini(1,0,n);
    while (q--) {
        int qt; cin >> qt;
        if (qt==1) {
            int a,b,v; cin >> a >> b >> v;
            upd(1,0,n,a-1,b,v,0);
        }
        else if (qt==2) {
            int a,b,v; cin >> a >> b >> v;
            upd(1,0,n,a-1,b,v,1);
        }
        else {
            int a,b; cin >> a >> b;
            cout << qu(1,0,n,a-1,b) << '\n';
        }
    }
}
