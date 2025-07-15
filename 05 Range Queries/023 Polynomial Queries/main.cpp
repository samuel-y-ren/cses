// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-22 20:14:27 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;


struct nd {
    ll s,c; int i;
};

nd st[MAXN*4];
int t[MAXN];

void ini(int u, int l, int r) {
    if (l+1==r) {
        st[u].s=t[l];
        return;
    }
    const int m = (l+r+1)/2;
    ini(2*u,l,m);
    ini(2*u+1,m,r);
    st[u].s = st[2*u].s+st[2*u+1].s;
}

void ps(int u, int l, int r) {
    if (!st[u].c && !st[u].i) return;
    if (l+1<r) {
        const int m = (l+r+1)/2;
        const ll d = m-l;
        st[2*u].s += (d*st[u].c+(d*(d+1)/2)*st[u].i);
        const ll e = r-m;
        st[2*u+1].s += (e*st[u].c+(e*(e+1)/2+d*e)*st[u].i);
        st[2*u].c += st[u].c;
        st[2*u+1].c += st[u].c + d*st[u].i;
        st[2*u].i += st[u].i;
        st[2*u+1].i += st[u].i;
    }
    st[u].c=0; st[u].i=0;
}

void upd(int u, int l, int r, int ul, int ur) {
    if (r<=ul || ur<=l) return;
    if (ul<=l && r<=ur) {
        st[u].c += l-ul;
        st[u].i++;
        const ll d = r-l;
        st[u].s += (l-ul)*d+d*(d+1)/2;
        return;
    }
    ps(u,l,r);
    const int m = (l+r+1)/2;
    upd(2*u,l,m,ul,ur); upd(2*u+1,m,r,ul,ur);
    st[u].s = st[2*u].s + st[2*u+1].s;

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
    for (int i=0; i<n; i++) cin >> t[i];
    ini(1,0,n);
    while (q--) {
        int qt,a,b; cin >> qt >> a >> b;
        if (qt==1) upd(1,0,n,a-1,b);
        else cout << qu(1,0,n,a-1,b) << '\n';
    }
}
