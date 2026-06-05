// File: main.cpp
// Author: Samuel Ren
// Created: 2025-09-18 21:12:42 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mn=3005;
int n;
ll cst[mn][mn];
ll ps[mn];
ll ips[mn];
int c[mn];

inline ll ct(int i, int k, int j) {
    return ips[i]-ips[k]+k*(ps[k]-ps[i]) + ips[j]-ips[k]-k*(ps[j]-ps[k]);
}

void pp() {
    for (int i=0; i<n; ++i) {
        ps[i+1]=ps[i]+c[i];
        ips[i+1]=ips[i]+(ll)c[i]*i;
    }
    for (int i=0; i<=n; ++i) {
        int k=i;
        cst[i][i]=0;
        for (int j=i+1; j<=n; ++j) {
            cst[i][j]=ct(i,k,j);
            while (ct(i,k+1,j)<cst[i][j]) cst[i][j]=ct(i,++k,j);
        }
    }
}

vector<ll> dp(mn,1000000000000000000ll),dq(mn);
void dc(int l, int r, int tl, int tr) {
    if (l==r) return;
    int m = (l+r)>>1;
    int tv=-1;
    dq[m]=1000000000000000000ll;
    for (int i=tl; i<min(tr,m+1); ++i) if (dp[i]+cst[i][m]<dq[m]) {
        dq[m]=dp[i]+cst[i][m];
        tv=i;
    }
    dc(l,m,tl,tv+1);
    dc(m+1,r,tv,tr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k; cin >> n >> k;
    for (int i=0; i<n; ++i) cin >> c[i];
    pp();
    dp[0]=0;
    while (k--) {
        dc(0,n+1,0,n+1);
        swap(dp,dq);
    }
    cout << dp[n];
}