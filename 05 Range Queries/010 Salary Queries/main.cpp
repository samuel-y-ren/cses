// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-15 22:10:10 PST

#include <bits/stdc++.h>
using namespace std;

const int MAXN=400005;

int s[MAXN];
int st[MAXN*4];

void ini(int u, int l, int r) {
    if (l+1==r) {
        st[u]=s[l];
        return;
    }
    int m = (l+r+1)/2;
    ini(2*u,l,m);
    ini(2*u+1,m,r);
    st[u]=st[2*u]+st[2*u+1];
}

void upd(int u, int l, int r, int v, int k) {
    if (v<l||r<=v) return;
    st[u]+=k;
    if (l+1==r) return;
    int m = (l+r+1)/2;
    upd(2*u,l,m,v,k);
    upd(2*u+1,m,r,v,k);
}

int qu(int u, int l, int r, int ql, int qr) {
    if (qr<=l || r<=ql) return 0;
    if (ql<=l && r<=qr) return st[u];
    int m = (l+r+1)/2;
    return qu(2*u,l,m,ql,qr)+qu(2*u+1,m,r,ql,qr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    vector<int> cc(n);
    int p[n]; 
    for (int i=0; i<n; i++) {
        cin >> p[i];
        cc[i]=p[i];
    }
    char oqt[q];
    int oq[q][2];
    for (int i=0; i<q; i++) {
        cin >> oqt[i] >> oq[i][0] >> oq[i][1];
        if (oqt[i]=='!') cc.push_back(oq[i][1]);
    }
    int m = cc.size();
    sort(cc.begin(),cc.end());
    for (int i=0; i<n; i++) s[lower_bound(cc.begin(),cc.end(),p[i])-cc.begin()]++;
    ini(1,0,m);
    for (int i=0; i<q; i++) {
        if (oqt[i]=='!') {
            oq[i][0]--;
            int cu=lower_bound(cc.begin(),cc.end(),p[oq[i][0]])-cc.begin();
            upd(1,0,m,cu,-1);
            p[oq[i][0]]=oq[i][1];
            cu=lower_bound(cc.begin(),cc.end(),p[oq[i][0]])-cc.begin();
            upd(1,0,m,cu,1);
        }
        else {
            int lb=lower_bound(cc.begin(),cc.end(),oq[i][0])-cc.begin();
            int ub=upper_bound(cc.begin(),cc.end(),oq[i][1])-cc.begin();
            cout << qu(1,0,m,lb,ub) << '\n';
        }
    }
}
