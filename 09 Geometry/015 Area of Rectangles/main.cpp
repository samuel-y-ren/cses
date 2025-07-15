// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-13 10:38:05 PST

#include <bits/stdc++.h>
using namespace std;

inline pair<int,int> operator^ (const pair<int,int>& a, const pair<int,int>& b) {
    if (a.first==b.first) return {a.first,a.second+b.second};
    else if (a.first<b.first) return a;
    else return b;
}
inline void operator+= (pair<int,int>& a, int b) {
    a.first+=b;
}
inline pair<int,int> operator+ (const pair<int,int>& a, int b) {
    return {a.first+b,a.second};
}

struct segt {
    vector<pair<int,int>> t;
    vector<int> lz;
    int n;
    segt(int n_) : n(n_) {
        t.resize(2*n);
        lz.resize(n,0);
        for (int i=0; i<n; ++i) t[i+n]={0,1};
        for (int i=n-1; i; --i) t[i]=t[i<<1]^t[(i<<1)|1];
    }
    inline void ad(int x, int v) {
        t[x]+=v;
        if (x<n) lz[x]+=v;
    }
    inline void rb(int x) {
        for (x>>=1;x;x>>=1) t[x]=(t[x<<1]^t[(x<<1)|1])+lz[x];
    }
    void psl(int x) {
        for (int h=31-__builtin_clz(x); h; --h) {
            int i=x>>h;
            if (lz[i]) {
                ad(i<<1,lz[i]);
                ad((i<<1)|1,lz[i]);
                lz[i]=0;
            }
        }
    }
    void upd(int l, int r, int v) {
        for (int tl=l+n, tr=r+n;tl<tr;tl>>=1,tr>>=1) {
            if (tl&1) ad(tl++,v);
            if (tr&1) ad(--tr,v);
        }
        rb(l+n); rb(r+n-1);
    }
    int qr() {
        return t[1].second;
    }
};

const int MV=1<<20;
segt st(MV<<1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pair<pair<int,int>,int>> v[MV*2];
    while (n--) {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        v[x1+MV].push_back({{y1,y2},1});
        v[x2+MV].push_back({{y1,y2},-1});
    }
    long long t=0;
    for (int i=0; i<(MV<<1); ++i) {
        for (auto& j : v[i]) st.upd(j.first.first+MV,j.first.second+MV,j.second);
        t+=(MV<<1)-st.qr();
    }
    cout << t;
}
