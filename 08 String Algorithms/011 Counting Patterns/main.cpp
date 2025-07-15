// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-04 12:32:53 PST

#include <bits/stdc++.h>
using namespace std;

const int k=26;

struct v {
    v* p[k];
    v* pr;
    v* f;
    int t;
    int pv;
    bool vs;
    v(int g, v* par) : pr(par), pv(g) {
        fill(p,p+k,nullptr);
        f=nullptr;
        t=0;
        vs=false;
    }
    v* tr(int x) {
        if (!p[x]) p[x]=new v(x, this);
        return p[x];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int m; cin >> m;
    v* p[m];
    v* rt = new v(-1, nullptr);
    (*rt).pr=rt;
    for (int i=0; i<m; ++i) {
        string d; cin >> d;
        v* ct = rt;
        for (char c : d) ct=(*ct).tr(int(c)-97);
        p[i]=ct;
    }
    queue<v*> q;
    q.push(rt);
    while (q.size()) {
        v& pt=*(q.front());
        q.pop();
        v* fp=(*pt.pr).f;
        while (fp&&!(*fp).p[pt.pv]) fp=(*fp).f;
        if (fp) pt.f=(*fp).p[pt.pv];
        else pt.f=rt;
        if (pt.f==&pt) pt.f=rt;
        for (int i=0; i<k; ++i) {
            if (pt.p[i]) {
                q.push(pt.p[i]);
                continue;
            }
            fp=pt.f;
            if (fp==rt) pt.p[i]=rt;
            while (fp&&!(*fp).p[i]) fp=(*fp).f;
            if (fp) pt.p[i]=(*fp).p[i];
            else pt.p[i]=rt;
        }
    }
    v* ptr=rt;
    for (char c : s) ++((*(ptr=(*ptr).p[int(c)-97])).t);
    q.push(rt);
    vector<v*> po;
    while (q.size()) {
        v& pt=*(q.front());
        q.pop();
        if (pt.vs) continue;
        pt.vs=true;
        for (int i=0; i<k; ++i) q.push(pt.p[i]);
        po.push_back(&pt);
    }
    reverse(po.begin(), po.end());
    for (auto i : po) (*(*i).f).t+=(*i).t;
    for (auto i : p) cout << (*i).t << '\n';
}