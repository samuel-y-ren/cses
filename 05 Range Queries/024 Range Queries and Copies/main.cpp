// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-22 20:39:14 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;
int t[MAXN];

struct nd{
    ll s;
    nd* l; nd* r;
};

vector<nd*> rt;

void ini(nd &u, int l, int r) {
    if (l+1==r) {
        u.s=t[l];
        return;
    }
    const int m = (l+r+1)/2;
    u.l=new nd;
    ini(*u.l,l,m);
    u.r=new nd;
    ini(*u.r,m,r);
    u.s=(*u.l).s+(*u.r).s;
}

void upd(nd &u, int l, int r, int v, int k) {
    if (l+1==r) {
        u.s=k;
        return;
    }
    const int m = (l+r+1)/2;
    if (v<m) {
        u.l=new nd(*u.l);
        upd(*u.l,l,m,v,k);
    }
    else {
        u.r=new nd(*u.r);
        upd(*u.r,m,r,v,k);
    }
    u.s=(*u.l).s+(*u.r).s;
}

ll qu(nd &u, int l, int r, int ql, int qr) {
    if (qr<=l||r<=ql) return 0;
    if (ql<=l&&r<=qr) return u.s;
    const int m = (l+r+1)/2;
    return qu(*u.l,l,m,ql,qr)+qu(*u.r,m,r,ql,qr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    for (int i=0; i<n; i++) cin >> t[i];
    rt.push_back(new nd);
    ini(*rt[0],0,n);
    while (q--) {
        int qt; cin >> qt;
        if (qt==1) {
            int k,a,x; cin >> k >> a >> x;
            k--;
            rt[k]=new nd(*rt[k]);
            upd(*rt[k],0,n,a-1,x);
        }
        else if (qt==2) {
            int k,a,b; cin >> k >> a >> b;
            cout << qu(*rt[k-1],0,n,a-1,b) << '\n';
        }
        else {
            int k; cin >> k;
            rt.push_back(rt[k-1]);
        }
    }
}
