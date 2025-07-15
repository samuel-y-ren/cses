// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-12 16:24:59 PST

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    lines l; l.l=0; l.r=m+1;
    while (n--) {
        int y1,y2; cin >> y1 >> y2;
        l.p.emplace_back((y2-y1)/m,y1);
    }
    l.pc();
    for (int i : l.ans) cout << i << ' ';
}
