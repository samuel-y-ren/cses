// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-18 11:05:43 PST

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int st[MAXN*4];

void upd(int u, int l, int r, int v, bool t) {
    if (v<l||r<=v) return;
    st[u] += (t ? 1 : -1);
    if (l+1==r) return;
    const int m = (l+r+1)/2;
    upd(2*u,l,m,v,t);
    upd(2*u+1,m,r,v,t);
}

int qu(int u, int l, int r, int qr) {
    if (l>=qr) return 0;
    if (r<=qr) return st[u];
    const int m = (l+r+1)/2;
    return qu(2*u,l,m,qr) + qu(2*u+1,m,r,qr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    int x[n]; for (int i=0; i<n; i++) cin >> x[i];
    map<int,int> np;
    vector<pair<int,int>> oq[n];
    int ans[q];
    for (int i=0; i<q; i++) {
        int a,b; cin >> a >> b;
        oq[a-1].push_back({b,i});
    }
    for (int i=n-1; i>=0; i--) {
        if (np.find(x[i]) != np.end()) upd(1,0,n,np[x[i]],0);
        upd(1,0,n,i,1);
        np[x[i]]=i;
        for (auto j : oq[i]) ans[j.second]=qu(1,0,n,j.first);
    }
    for (int i=0; i<q; i++) cout << ans[i] << '\n';
}
