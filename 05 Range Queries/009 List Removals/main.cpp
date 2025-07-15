// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-15 21:16:25 PST

#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

int st[MAXN*4];

void ini(int u, int l, int r) {
    if (l+1!=r) {
        int m = (l+r+1)/2;
        ini(2*u,l,m);
        ini(2*u+1,m,r);
    }
    st[u]=r-l;
}

int wu(int u, int l, int r, int k) {
    st[u]--;
    if (l+1==r) return l;
    if (st[2*u]>k) return wu(2*u,l,(l+r+1)/2,k);
    else return wu(2*u+1,(l+r+1)/2,r,k-st[2*u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ini(1,0,n);
    int x[n]; for (int i=0; i<n; i++) cin >> x[i];
    for (int i=0; i<n; i++) {
        int p; cin >> p;
        cout << x[wu(1,0,n,p-1)] << ' ';
    }
}
