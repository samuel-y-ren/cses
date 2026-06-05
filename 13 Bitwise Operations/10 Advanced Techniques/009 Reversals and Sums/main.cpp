// File: main.cpp
// Author: Samuel Ren
// Created: 2025-09-03 11:40:46 PST

#include <bits/stdc++.h>
using namespace std;

struct nd { 
    nd* l; nd* r;
    int s; int p;
    bool i;
    int v; long long sm;
    nd(int v_, int p_) : l(0), r(0), s(1), p(p_), i(0), v(v_), sm(v_) {}
};
typedef nd* pnd;

int sz(pnd t) {
    return (t?t->s:0);
}
long long sm(pnd t) {
    return (t?t->sm:0ll);
}
void ut(pnd t) {
    t->s=sz(t->l)+sz(t->r)+1;
    t->sm=sm(t->l)+sm(t->r)+t->v;
}
void ps(pnd t) {
    if (t&&t->i) {
        t->i=0;
        swap(t->l,t->r);
        if (t->l) t->l->i^=1;
        if (t->r) t->r->i^=1;
    }
}

void split(pnd t, pnd& l, pnd& r, int k, int s=0) {
    if (!t) {
        l=r=0; return;
    }
    ps(t);
    int ik=s+sz(t->l);
    if (k<=ik) {
        split(t->l,l,t->l,k,s);
        r=t;
    } else {
        split(t->r,t->r,r,k,ik+1);
        l=t;
    }
    ut(t);
}

void merge(pnd& t, pnd l, pnd r) {
    if (!l||!r) {
        t=(l?l:r); return;
    }
    ps(l); ps(r);
    if (l->p>r->p) {
        merge(l->r,l->r,r);
        t=l;
    } else {
        merge(r->l,l,r->l);
        t=r;
    }
    ut(t);
}

void reverse(pnd t, int l, int r) {
    pnd t1,t2,t3;
    split(t,t1,t2,l);
    split(t2,t2,t3,r-l);
    t2->i^=1;
    merge(t,t1,t2);
    merge(t,t,t3);
}

void hp(pnd t) {
    pnd m=t;
    if (t->l&&t->l->p>m->p) m=t->l;
    if (t->r&&t->r->p>m->p) m=t->r;
    if (m!=t) {
        swap(m->p,t->p);
        hp(m);
    }
}

pnd bd(int* s, int* pr, int n) {
    if (!n) return 0;
    int m=n/2;
    pnd t=new nd(*(s+m), *(pr+m));
    t->l=bd(s,pr,m);
    t->r=bd(s+m+1,pr+m+1,n-m-1);
    hp(t);
    ut(t);
    return t;
}

long long sm(pnd t, int l, int r) {
    pnd t1,t2,t3;
    split(t,t1,t2,l);
    split(t2,t2,t3,r-l);
    long long s=t2->sm;
    merge(t,t1,t2);
    merge(t,t,t3);
    return s;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int v[n]; for (int i=0; i<n; ++i) cin >> v[i];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> rng(INT_MIN, INT_MAX);
    int p[n]; for (int i=0; i<n; ++i) p[i]=rng(gen);
    pnd t=bd(v, p, n);
    while (m--) {
        int q,a,b; cin >> q >> a >> b;
        if (q==2) cout << sm(t,a-1,b) << '\n';
        else reverse(t,a-1,b);
    }
}