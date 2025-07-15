// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-11 18:16:21 PST

#include <bits/stdc++.h>
using namespace std;

inline void smax(int& a, int b) {
    if (a<b) a=b;
}

struct lines{
    struct seg{
        int l,r,m,b;
        seg(int l_, int r_, int m_, int b_) : l(l_), r(r_), m(m_), b(b_) {}
        seg() {
            l=r=0;
        }
    };
    int l,r;
    vector<pair<int,int>> p;
    lines() {}
    vector<int> ans;
    void pc() {
        if (!p.size()) {
            ans.resize(r-l,-1);
            return;
        }
        sort(p.begin(),p.end());
        ans.resize(r-l);
        vector<seg> v;
        for (const auto& i : p) {
            seg d;
            while (v.size()&&i.first*(d=v.back()).l+i.second>d.m*d.l+d.b) v.pop_back();
            if (v.size()&&i.first*(d.r-1)+i.second>d.m*(d.r-1)+d.b) v.back().r=(d.b-i.second)/(i.first-d.m)+1;
            if (v.size()) v.emplace_back(v.back().r,r-l,i.first,i.second);
            else v.emplace_back(0,r-l,i.first,i.second);
        }
        int s=0;
        for (int i=0; i<r-l; ++i) {
            if (v[s].r==i) ++s;
            ans[i]=v[s].m*i+v[s].b;
        }

    }
};

struct segt{
    int n;
    vector<lines> t;
    segt(int n_) : n(n_) {
        t.resize(2*n);
        for (int i=0; i<n; ++i) t[i+n].r=(t[i+n].l=i)+1;
        for (int i=n-1; i; --i) if (t[i<<1].r&&t[(i<<1)|1].r&&t[i<<1].l<t[(i<<1)|1].l) {
            t[i].l=t[i<<1].l;
            t[i].r=t[(i<<1)|1].r;
        }
    }
    void ins(int l, int r, int m, int b) {
        int il=l;
        for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) {
                t[l].p.emplace_back(m,b+m*(t[l].l-il));
                ++l;
            }
            if (r&1) {
                --r;
                t[r].p.emplace_back(m,b+m*(t[r].l-il));
            }
        }
    }
    void ans() {
        for (int i=1; i<(n<<1); ++i) if (t[i].r) t[i].pc();
    }
    int qr(int id) {
        int ans=-1;
        int oi=id;
        for (id+=n; id; id>>=1) if (t[id].r) smax(ans,t[id].ans[oi-t[id].l]);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    segt st(m+1);
    while (n--) {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        st.ins(x1,x2+1,(y2-y1)/(x2-x1),y1);
    }
    st.ans();
    for (int i=0; i<=m; ++i) {
        cout << st.qr(i) << ' ';
    }
}
