// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-13 22:56:37 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200005;
const int MOD = 1000000007;

int st[MAXN*4];
int n;

void upd(int t, int v) {
    int l=0, h=n;
    int u = 1;
    while (l+1!=h) {
        st[u] += v;
        st[u] %= MOD;
        int m = (l+h+1)/2;
        if (t<m) {
            u = 2*u;
            h=m;
        }
        else {
            u = 2*u+1;
            l=m;
        }
    }
    st[u] += v;
    st[u] %= MOD;
}

int q(int u, int rl, int rh, int th) { 
    if (rh<=th) return st[u];
    if (rl>=th) return 0;
    int m = (rl+rh+1)/2;
    return (q(2*u,rl,m,th)+q(2*u+1,m,rh,th))%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int x[n], xs[n]; 
    for (int i=0; i<n; i++) {
        cin >> x[i];
        xs[i]=x[i];
    }
    sort(xs,xs+n);
    int xi[n]; for (int i=0; i<n; i++) xi[i]=lower_bound(xs,xs+n,x[i])-xs;
    int dp[n];
    int tot=0;
    for (int i=0; i<n; i++) {
        dp[i] = q(1,0,n,xi[i])+1;
        upd(xi[i],dp[i]);
        tot = (tot+dp[i])%MOD;
    }
    cout << tot;
}
