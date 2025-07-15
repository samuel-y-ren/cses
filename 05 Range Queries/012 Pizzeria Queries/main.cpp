// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-16 11:22:39 PST

#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

int stl[MAXN*4], str[MAXN*4];
int pl[MAXN], pr[MAXN];

void ini(int u, int l, int r, int (&st)[], int (&p)[]) {
    if (l+1==r) {
        st[u]=p[l];
        return;
    }
    const int m = (l+r+1)/2;
    ini(2*u,l,m,st,p);
    ini(2*u+1,m,r,st,p);
    st[u]=min(st[2*u], st[2*u+1]);
}

void upd(int u, int l, int r, int k, int v, int (&st)[]) {
    if (k<l || k>=r) return;
    if (l+1==r) {
        st[u]=v;
        return;
    }
    int m = (l+r+1)/2;
    upd(2*u,l,m,k,v,st);
    upd(2*u+1,m,r,k,v,st);
    st[u]=min(st[2*u],st[2*u+1]);
}

int qu(int u, int l, int r, int ql, int qr, int (&st)[]) {
    if (r<=ql || qr<=l) return 2000000000;
    if (ql<=l && r<=qr) return st[u];
    int m = (l+r+1)/2;
    return min(qu(2*u,l,m,ql,qr,st), qu(2*u+1,m,r,ql,qr,st));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    for (int i=0; i<n; i++) {
        cin >> pl[i];
        pr[i]=pl[i];
        pl[i]-=i;
        pr[i]+=i;
    }
    ini(1,0,n,stl,pl);
    ini(1,0,n,str,pr);
    while (q--) {
        int qt; cin >> qt;
        if (qt==1) {
            int k,v; cin >> k >> v;
            k--;
            upd(1,0,n,k,v-k,stl);
            upd(1,0,n,k,v+k,str);
        }
        else {
            int k; cin >> k;
            k--;
            cout << min(qu(1,0,n,0,k,stl)+k, qu(1,0,n,k,n,str)-k) << '\n';
        }
    }
}
