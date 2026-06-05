// File: main.cpp
// Author: Samuel Ren
// Created: 2025-09-15 10:04:49 PST

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 lll;

struct nd {
    int f; ll t;
    int df; ll dt;
    nd(int f_, ll t_, int df_, ll dt_): f(f_), t(t_), df(df_), dt(dt_) {}
    nd(int f_, ll t_) : f(f_), t(t_), df(1), dt(0) {}
};

struct comp {
    using is_transparent=void;
    bool operator()(const nd& n1, const nd& n2) const {return n1.f<n2.f;}
    bool operator()(const nd& n, const int& m) const {return n.dt<(lll)m*-n.df;}
    bool operator()(const int& m, const nd& n) const {return n.dt>(lll)m*-n.df;}
};

bool rp(int f, ll t, const nd& node) {
    return (lll)-node.dt*(f-node.f)+(lll)node.df*(t-node.t)<=0;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x; cin >> n >> x;
    int s[n], f[n];
    for (int i=0; i<n; ++i) cin >> s[i];
    for (int i=0; i<n; ++i) cin >> f[i];
    set<nd,comp> ch; ch.insert(nd(x,0));
    for (int i=0; i<n-1; ++i) {
        if (f[i]>=x) continue;
        auto ptr=ch.lower_bound(s[i]); 
        nd nc(f[i], ptr->t+(ll)s[i]*ptr->f);
        while (rp(nc.f, nc.t, (*(ptr=ch.lower_bound(nc))))) ch.erase(ptr);
        if (ptr==ch.begin()) {
            nc.df=ptr->f-nc.f;
            nc.dt=ptr->t-nc.t;
            ch.insert(nc);
            continue;
        }
        bool e=false;
        while (rp(nc.f, nc.t, (*(--(ptr=ch.lower_bound(nc)))))) {
            if (ptr==ch.begin()) {
                nd pv=*ptr;
                pv.df=nc.f-pv.f;
                pv.dt=nc.t-pv.t;
                ch.erase(ptr);
                ptr=ch.begin();
                nc.df=ptr->f-nc.f;
                nc.dt=ptr->t-nc.t;
                ch.insert(pv);
                ch.insert(nc);
                e=false;
                break;
            }
            ch.erase(ptr);
            e=true;
        }
        if (e) {
            nd pv(ptr->f+ptr->df,ptr->t+ptr->dt);
            pv.df=nc.f-pv.f;
            pv.dt=nc.t-pv.t;
            ptr=ch.lower_bound(nc);
            nc.df=ptr->f-nc.f;
            nc.dt=ptr->t-nc.t;
            ch.insert(pv);
            ch.insert(nc);
        }
    }
    auto ptr=ch.lower_bound(s[n-1]);
    cout << ptr->t+(ll)s[n-1]*ptr->f;
}