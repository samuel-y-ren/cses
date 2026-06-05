// File: main.cpp
// Author: Samuel Ren
// Created: 2025-09-17 21:23:45 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mn=3005;
int x[mn], ps[mn];
vector<ll> dp(mn,1000000000000000000ll), dq(mn);

inline ll sq(int v) {return (ll)v*v;}

void dnq(int l, int r, int lt, int rt) {
    if (l==r) return;
    int m=(l+r)>>1;
    ll tv=1000000000000000000ll; int ti=-1;
    for (int i=lt; i<min(m+1,rt); ++i) if (dp[i]+sq(ps[m]-ps[i])<tv) {
        tv=dp[i]+sq(ps[m]-ps[i]);
        ti=i;
    }
    dq[m]=tv;
    dnq(l,m,lt,ti+1);
    dnq(m+1,r,ti,rt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    for (int i=0; i<n; ++i) {
        cin >> x[i]; 
        ps[i+1]=ps[i]+x[i];
    }
    dp[0]=0;
    for (int i=0; i<k; ++i) {
        dnq(0,n+1,0,n+1);
        swap(dp,dq);
    }
    cout << dp[n];
}
