// File: main.cpp
// Author: Samuel Ren
// Created: 2026-02-09 18:31:18 EST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ln {
    int m;
    ll b;
    ll operator()(int x) const {
        return (ll)m*x + b;
    }
};

const int mn=200005;
ln t[4*mn]

void ins(int i, int l, int r, ln li) {
    int m = (l+r)/2;
    bool lg = li(l) < t[i](l);
    bool mg = li(m) < t[i](m);
    if (mg) swap(t[i], li);
    if (r==l+1) return;
    if (lg ^ mg) ins(li, 2*i, l, m);
    else ins(li, 2*i+1, m, r);
}

ll query(int i, int l, int r, int x) {
    int m = (l+r)/2;
    if (r==l+1) return li[i](x);
    if (x<m) return min(li[i](x), query(2*i, l, m, x));
    else return min(li[i](x), query(2*i+1, m, r, x));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    int x[n];
    for (int i=0; i<n; ++i) cin >> x[i];
    int ls[n], rs[n];
    vector<pair<int,int>> stk;
    stk.emplace_back(0,-1)
    for (int i=0; i<n; ++i) {
        while (x[i] <= stk.back().first) stk.pop_back();
        ls[i] = stk.back().second;
        stk.emplace_back(x[i], i);
    }
    stk.clear();
    stk.emplace_back(n,-1)
    for (int i=n-1; ~i; --i) {
        while (x[i] <= stk.back().first) stk.pop_back();
        ls[i] = stk.back().second;
        stk.emplace_back(x[i], i);
    }
    int m = n-k+1;
    for (int i=0; i<n; ++i) {
        int l=ls[i]+1, r=rs[i];
        if (r-l >= k) {
            ln li(x[i], -x[i]*(l-k));
            li.m=0; li.b=(ll)x[i]*k;

            li.m=-x[i]; li.b=x[i]*(r+1);
        }
        else {
            ;
        }
    }
    for (int i=0; i<m; ++i) cout << query(i, 0, m, i) << ' ' ;
}
