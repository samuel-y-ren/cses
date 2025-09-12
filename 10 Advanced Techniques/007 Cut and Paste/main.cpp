// File: main.cpp
// Author: Samuel Ren
// Created: 2025-09-03 09:26:41 PST

#include <bits/stdc++.h>
using namespace std;

struct nd{
    nd* l; nd* r;
    int p, s;
    char v;
    nd(char v_, int p_) : l(0), r(0), p(p_), s(1), v(v_) {};
};
typedef nd* pnd;

inline int sz(pnd p) {
    return (p ? p->s : 0);
}
inline void usz(pnd p) {
    if (p) p->s=sz(p->l)+sz(p->r)+1;
}

void split(pnd t, pnd& l, pnd& r, int k, int s=0) {
    if (!t) {
        l=r=0;
        return;
    }
    int ik=s+sz(t->l);
    if (k<=ik) {
        split(t->l, l, t->l, k, s);
        r=t;
    } else {
        split(t->r, t->r, r, k, ik+1);
        l=t;
    }
    usz(t);
}

void merge(pnd& t, pnd l, pnd r) {
    if (!l||!r) {
        t=(l?l:r);
        return;
    }
    if (l->p > r->p) {
        merge(l->r,l->r,r); 
        t=l;
    } else {
        merge(r->l,l,r->l);
        t=r;
    }
    usz(t);
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

pnd bd(__cxx11::basic_string<char>::iterator s, int* pr, int n) {
    if (!n) return 0;
    int m=n/2;
    pnd t=new nd(*(s+m), *(pr+m));
    t->l=bd(s,pr,m);
    t->r=bd(s+m+1,pr+m+1,n-m-1);
    hp(t);
    usz(t);
    return t;
}

void ot(pnd p) {
    if (p) {
        ot(p->l);
        cout << p->v;
        ot(p->r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> rng(INT_MIN, INT_MAX);
    int p[n]; for (int i=0; i<n; ++i) p[i]=rng(gen);
    pnd t=bd(s.begin(), p, n);
    while (m--) {
        int a, b; cin >> a >> b;
        pnd t1,t2,t3;
        split(t,t1,t2,--a);
        split(t2,t2,t3,b-a);
        merge(t,t1,t3);
        merge(t,t,t2);
    }
    ot(t);
}
