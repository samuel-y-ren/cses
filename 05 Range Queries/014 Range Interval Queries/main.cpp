// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-17 19:54:18 PST

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int st[MAXN*4];

void upd(int u, int l, int r, int v) {
    if (l>v || r<=v) return;
    st[u]++;
    if (l+1==r) return;
    const int m = (l+r+1)/2;
    upd(2*u,l,m,v);
    upd(2*u+1,m,r,v);
}

int qu(int u, int l, int r, int qlb, int qrb) {
    if (l>=qrb || qlb>=r) return 0;
    if (qlb<=l && r<=qrb) return st[u];
    const int m = (l+r+1)/2;
    return qu(2*u,l,m,qlb,qrb)+qu(2*u+1,m,r,qlb,qrb);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    int x[n];
    int xo[n];
    for (int i=0; i<n; i++) {
        cin >> x[i];
        xo[i]=x[i];
    }
    sort(x,x+n);
    int ans[q]; for (int i=0; i<q; i++) ans[i]=0;
    vector<pair<pair<int,int>,pair<int,bool>>> oq[n+1];
    for (int i=0; i<q; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        int lb = lower_bound(x,x+n,c)-x, ub = lower_bound(x,x+n,d+1)-x;
        oq[a-1].push_back({{lb,ub},{i,true}});
        oq[b].push_back({{lb,ub},{i,false}});
    }
    for (int i=n-1; i>=0; i--) {
        upd(1,0,n,lower_bound(x,x+n,xo[i])-x);
        for (auto bq : oq[i]) {
            ans[bq.second.first] += (bq.second.second ? 1 : -1) * qu(1,0,n,bq.first.first,bq.first.second);
        }
    }
    for (int i=0; i<q; i++) cout << ans[i] << '\n';
}
