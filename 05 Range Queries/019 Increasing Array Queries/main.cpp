// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-18 19:10:01 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cc(const int &a, const pair<int,int> &b) {
    return a>b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    int x[n]; for (int i=0; i<n; i++) cin >> x[i];
    ll ans[q];
    vector<pair<int,int>> oq[n];
    for (int i=0; i<q; i++) {
        int a,b; cin >> a >> b;
        oq[a-1].push_back({b,i});
    }
    ll ps[n+1]; ps[0]=0;
    for (int i=0; i<n; i++) ps[i+1]=ps[i]+x[i];
    vector<pair<int,int>> stk={{2000000000,n}};
    vector<pair<ll,ll>> pstk={{0ll,0ll}};
    for (int i=n-1; i>=0; i--) {
        while (x[i]>stk.back().first) {
            stk.pop_back();
            pstk.pop_back();
        }
        ll v = (ll)(stk.back().second-i)*x[i];
        pstk.push_back({v, pstk.back().second+v});
        stk.push_back({x[i],i});
        for (auto j : oq[i]) {
            int k = upper_bound(stk.begin(), stk.end(), j.first, cc)-stk.begin();
            ans[j.second] = pstk.back().second-pstk[k].second;
            ans[j.second] += (ll)(j.first-stk[k].second)*stk[k].first;
            ans[j.second] -= ps[j.first]-ps[i];
        }
    }
    for (ll i : ans) cout << i << '\n';
}
