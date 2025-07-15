// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-15 21:05:50 PST

#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

int h[MAXN];
int st[MAXN*4];

void ini(int u, int l, int r) {
    if (l+1==r) {
        st[u]=h[l];
        return;
    }
    int m = (l+r+1)/2;
    ini(2*u,l,m);
    ini(2*u+1,m,r);
    st[u]=max(st[2*u],st[2*u+1]);
}

int wu(int u, int l, int r, int v) {
    if (st[u]<v) return 0;
    if (l+1==r) {
        st[u]-=v;
        return l;
    }
    int m = (l+r+1)/2;
    int res;
    if (!(res=wu(2*u,l,m,v))) res=wu(2*u+1,m,r,v);
    st[u]=max(st[2*u],st[2*u+1]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> h[i];
    ini(1,1,n+1);
    while (m--) {
        int r; cin >> r;
        cout << wu(1,1,n+1,r) << ' ';
    }
}
