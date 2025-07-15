// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-17 20:21:19 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;
int n;

struct node{
    ll c,ps,ss,as;
};

node mg(const node &a, const node &b) {
    return {max(max(a.c,b.c),a.ss+b.ps),max(a.ps,a.as+b.ps),max(b.ss,b.as+a.ss),a.as+b.as};
}

int x[MAXN];
node st[4*MAXN];

void ini(int u, int l, int r) {
    if (l+1==r) {
        int nn=max(x[l],0);
        st[u] = {nn,nn,nn,x[l]};
        return;
    }
    const int m = (l+r+1)/2;
    ini(2*u,l,m); ini(2*u+1,m,r);
    st[u]=mg(st[2*u],st[2*u+1]);
}

vector<node> qn;

void rq(int u, int l, int r, int ql, int qr) {
    if (qr<=l || r<=ql) return;
    if (ql<=l && r<=qr) {
        qn.push_back(st[u]);
        return;
    }
    const int m = (l+r+1)/2;
    rq(2*u,l,m,ql,qr);
    rq(2*u+1,m,r,ql,qr);
}

ll qu(int a, int b) {
    rq(1,0,n,a,b);
    node nd=qn[0];
    for (int i=1; i<qn.size(); i++) nd=mg(nd,qn[i]);
    qn.clear();
    return nd.c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> n >> q;
    for (int i=0; i<n; i++) cin >> x[i];
    ini(1,0,n);
    while (q--) {
        int a,b; cin >> a >> b;
        cout << qu(a-1,b) << '\n';
    }
}
