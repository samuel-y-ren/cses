// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-13 08:57:45 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct seg {
    int m; ll b;
    seg() {
        m=0; b=-1000000000000000000;
    }
    seg(int m_, ll b_) : m(m_), b(b_) {}
    seg(int m_, int b_) : m(m_), b(b_) {}
    ll operator() (int x) {
        return (ll)x*m+b;
    }
};

inline void smax(ll& a, ll b) {
    if (a<b) a=b;
}

struct lc {
    struct sd {
        int l,m,r;
        sd() {};
        sd(int l_, int m_, int r_) : l(l_), m(m_), r(r_) {}
    };
    int n;
    vector<seg> t;
    vector<sd> m;
    lc(int n_) : n(n_) {
        t.resize(2*n);
        m.resize(2*n);
        for (int i=0; i<n; ++i) m[i+n]=sd(i,i,i+1);
        for (int i=n-1; i; --i) if (m[i<<1].r==m[(i<<1)|1].l) m[i]=sd(m[i<<1].l,m[i<<1].r,m[(i<<1|1)].r);
    }
    inline void sins(int id, int a, int b) {
        seg s(a,b);
        while (id<=(n<<1)) {
            if (t[id].m>s.m) swap(t[id],s);
            if (s(m[id].r-1)<=t[id](m[id].r-1)) break; //may be faster
            if (t[id](m[id].m)<s(m[id].m)) {
                swap(t[id],s);
                id<<=1;
            }
            else id=(id<<1)|1;
        }
    } 
    void ins(int l, int r, int a, int b) {
        for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) sins(l++,a,b);
            if (r&1) sins(--r,a,b);
        }
    }
    ll qr(int x) {
        ll ma=-1000000000000000000;
        ll ox=x;
        for (x+=n;x;x>>=1) smax(ma,t[x](ox));
        return ma;
    }
};

const int MAXM=100005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    lc st(MAXM);
    while (n--) {
        int qt; cin >> qt;
        if (qt==1) {
            int a,b,l,r; cin >> a >> b >> l >> r;
            st.ins(l,r+1,a,b);
        }
        else {
            int x; cin >> x;
            ll ans = st.qr(x);
            if (ans==-1000000000000000000) cout << "NO\n";
            else cout << ans << '\n';
        }
    }
}
