// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-14 21:43:30 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;
int n;

int x[MAXN];
ll s[MAXN*4], t[MAXN*4];

void ps(int u, int l, int r) {
    if (!t[u]) return;
    s[u] += (r-l)*t[u];
    if (r>l+1) {
        t[2*u]+=t[u];
        t[2*u+1]+=t[u];
    }
    t[u]=0;
}

void ini(int u, int l, int r) {
    if (l+1==r) {
        s[u]=x[l];
        return;
    }
    int m = (l+r+1)/2;
    ini(2*u,l,m);
    ini(2*u+1,m,r);
    s[u]=s[2*u]+s[2*u+1];
}

ll qr(int k) {
    int u=1,l=0,r=n;
    while (l+1!=r) {
        ps(u,l,r);
        int m = (l+r+1)/2;
        if (k<m) {
            r=m;
            u=2*u;
        }
        else {
            l=m;
            u=2*u+1;
        }
    }
    ps(u,l,r);
    return s[u];
}

void upd(int u, int l, int r, int ul, int ur, int v) {
    if (r<=ul || l>=ur) return;
    if (ul<=l && r<=ur) {
        t[u]+=v;
        return;
    }
    int m = (l+r+1)/2;
    upd(2*u,l,m,ul,ur,v);
    upd(2*u+1,m,r,ul,ur,v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> n >> q;
    for (int i=0; i<n; i++) cin >> x[i];
    ini(1,0,n);
    while (q--) {
        int qt; cin >> qt;
        if (qt==1) {
            int l,r,u; cin >> l >> r >> u;
            upd(1,0,n,l-1,r,u);
        }
        else {
            int k; cin >> k;
            cout << qr(k-1) << '\n';
        }
    }
}
