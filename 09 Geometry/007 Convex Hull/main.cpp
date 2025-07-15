// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-10 12:43:52 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct P {
    int x, y;
    P() {}
    P(int x_, int y_) : x(x_), y(y_) {}
};

ll operator* (const P& a, const P& b) {
    return (ll)a.x*b.x+(ll)a.y*b.y;
}

P operator+ (const P& a, const P& b) {
    return P(a.x+b.x,a.y+b.y);
}

P operator- (const P& a, const P& b) {
    return P(a.x-b.x,a.y-b.y);
}

bool operator< (const P& a, const P& b) {
    if (a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}

struct L {
    P s;
    P v;
    L(int x1, int y1, int x2, int y2) : s(x1,y1), v(x2,y2) {}
    L(const P& p1, const P& p2) : s(p1), v(p2-p1) {}
    P end() {
        return s+v;
    }
};

ll operator* (const P& p, const L& l) {
    P q(-l.v.y, l.v.x);
    P d(p.x-l.s.x, p.y-l.s.y);
    return d*q;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    P p[n]; for (int i=0; i<n; ++i) cin >> p[i].x >> p[i].y;
    sort(p,p+n);
    vector<L> uh;
    uh.emplace_back(p[0],p[n-1]);
    for (int i=1; i<n-1; ++i) {
        int rc=(int)uh.size();
        while (uh.size()&&p[i]*uh.back()>0) uh.pop_back();
        if (uh.size()) {
            if (!(p[i]*uh.back()) && p[i]<uh.back().end()) uh.pop_back();
            else if (rc==(int)uh.size()) continue;
        }
        if (!uh.size()) uh.emplace_back(p[0],p[i]);
        else uh.emplace_back(uh.back().end(),p[i]);
        uh.emplace_back(p[i],p[n-1]);
    }
    vector<L> lh;
    lh.emplace_back(p[n-1],p[0]);
    for (int i=n-2; i; --i) {
        int rc=(int)lh.size();
        while (lh.size()&&p[i]*lh.back()>0) lh.pop_back();
        if (lh.size()) {
            if (!(p[i]*lh.back()) && lh.back().end()<p[i]) lh.pop_back();
            else if (rc==(int)lh.size()) continue;
        }
        if (!lh.size()) lh.emplace_back(p[n-1],p[i]);
        else lh.emplace_back(lh.back().end(),p[i]);
        lh.emplace_back(p[i],p[0]);
    }
    cout << lh.size()+uh.size() << '\n';
    for (auto& i : uh) cout << i.s.x << ' ' << i.s.y << '\n';
    for (auto& i : lh) cout << i.s.x << ' ' << i.s.y << '\n';
}

