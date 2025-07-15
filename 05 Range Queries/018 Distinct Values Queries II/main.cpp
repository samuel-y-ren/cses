// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-18 12:02:30 PST
 
#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 200005;
 
int st[MAXN*4];
 
void upd(int u, int l, int r, int v, int k) {
    if (v<l||r<=v) return;
    if (l+1==r) {
        st[u]=k;
        return;
    }
    const int m = (l+r+1)/2;
    upd(2*u,l,m,v,k);
    upd(2*u+1,m,r,v,k);
    st[u] = min(st[2*u],st[2*u+1]);
}
 
bool qu(int u, int l, int r, int ql, int qr) {
    if (r<=ql || qr<=l) return true;
    if (ql<=l && r<=qr) {
        return (st[u]>=qr);
    }
    const int m = (l+r+1)/2;
    return (qu(2*u,l,m,ql,qr) && qu(2*u+1,m,r,ql,qr));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    int x[n]; for (int i=0; i<n; i++) cin >> x[i];
    map<int,set<int>> xp;
    for (int i=n-1; i>=0; i--) {
        if (xp.find(x[i]) != xp.end()) {
            upd(1,0,n,i,*xp[x[i]].begin());
            xp[x[i]].insert(i);
        }
        else {
            upd(1,0,n,i,n);
            xp[x[i]]={i};
        }
    }
    while (q--) {
        int qt; cin >> qt;
        if (qt==1) {
            int k,u; cin >> k >> u;
            k--;
            auto &ct = xp[x[k]];
            auto ptr = ct.find(k);
            if (ptr!=ct.begin()) {
                ptr--;
                int uv;
                auto p2=ct.upper_bound(k);
                if (p2==ct.end()) uv=n;
                else uv=*p2;
                upd(1,0,n,*ptr,uv);
            }
            ct.erase(k);
            if (!ct.size()) xp.erase(x[k]);
            x[k]=u;
            if (xp.find(u)!=xp.end()) {
                auto ptr = xp[u].upper_bound(k);
                if (ptr==xp[u].end()) upd(1,0,n,k,n);
                else upd(1,0,n,k,*ptr);
                xp[u].insert(k);
                ptr = xp[u].find(k);
                if (ptr != xp[u].begin()) {
                    ptr--;
                    upd(1,0,n,*ptr,k);
                }
            }
            else {
                upd(1,0,n,k,n);
                xp[u]={k};
            }
        }
        else {
            int a,b; cin >> a >> b;
            cout << (qu(1,0,n,a-1,b) ? "YES" : "NO") << '\n';
        }
    }
}