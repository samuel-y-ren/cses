// File: main.cpp
// Author: Samuel Ren
// Created: 2026-02-09 18:31:18 EST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ln {
    int m;
    ll b;
    ln(int m_, ll b_) : m(m_), b(b_) {}
    ln() : m(0), b(0) {}
    ll operator()(int x) const {
        return (ll)m*x + b;
    }
};

const int mn=200005;
ln t[4*mn];

void ins(int i, int l, int r, ln li) {
    // cout << i << ' ' << l << ' ' << r << ' ' << li.m << ' ' << li.b << '\n';

    int m = (l+r)/2;
    bool lg = li(l) > t[i](l);
    bool mg = li(m) > t[i](m);
    if (mg) {
        swap(t[i], li);
    }
    if (r==l+1) return;
    if (lg ^ mg) ins(2*i, l, m, li);
    else ins(2*i+1, m, r, li);
}

void pins(int i, int l, int r, int ql, int qr, ln li) {
    // cout << i << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << li.m << ' ' << li.b << endl;
    int m = (l+r)/2;
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr) {
        return ins(i, l, r, li);
    }
    pins(i*2, l, m, ql, qr, li);
    pins(i*2+1, m, r, ql, qr, li);
}

ll query(int i, int l, int r, int x) {
    int m = (l+r)/2;
    if (r==l+1) return t[i](x);
    if (x<m) return max(t[i](x), query(2*i, l, m, x));
    else return max(t[i](x), query(2*i+1, m, r, x));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    int x[n];
    for (int i=0; i<n; ++i) cin >> x[i];
    int ls[n], rs[n];
    vector<pair<int,int>> stk;
    stk.emplace_back(0,-1);
    for (int i=0; i<n; ++i) {
        while (x[i] <= stk.back().first) stk.pop_back();
        ls[i] = stk.back().second;
        stk.emplace_back(x[i], i);
    }
    stk.clear();
    stk.emplace_back(0,n);
    for (int i=n-1; ~i; --i) {
        while (x[i] <= stk.back().first) stk.pop_back();
        rs[i] = stk.back().second;
        stk.emplace_back(x[i], i);
    }
    int m = n-k+1;
    for (int i=0; i<n; ++i) {
        int l=ls[i]+1, r=rs[i];
        if (r-l >= k) {
            ln li(x[i], (ll)(l-k)*-x[i]);
            pins(1, 0, m, l-k, l, li);
            li.m=0;
            li.b=(ll)k*x[i];
            pins(1, 0, m, l, r-k, li);
            li.m=-x[i];
            li.b=(ll)x[i]*r;
            pins(1, 0, m, r-k, r, li);
        } else {
            ln li(x[i], (ll)(l-k)*-x[i]);
            pins(1, 0, m, l-k, r-k, li);
            li.m=0;
            li.b=(ll)(r-l)*x[i];
            pins(1, 0, m, r-k, l, li);
            li.m=-x[i];
            li.b=(ll)x[i]*r;
            pins(1, 0, m, l, r, li);
        }
    }
    for (int i=0; i<m; ++i) cout << query(1, 0, m, i) << ' ';
}
