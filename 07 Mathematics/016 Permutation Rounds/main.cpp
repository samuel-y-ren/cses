// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-02 19:19:19 PST

#include <bits/stdc++.h>
using namespace std;

const int MOD=1000000007;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int d[n+1]={};
    for (int i=2; i<=n; ++i) if (!d[i]) for (int j=i; j<=n; j+=i) d[j]=i;
    int p[n+1]; for (int i=1; i<=n; ++i) cin >> p[i];
    bool u[n+1]={};
    int mv[n+1]={};
    for (int i=1; i<=n; ++i) if (!u[i]) {
        int t=1;
        u[p[i]]=true;
        for (int x=p[i]; i!=x; u[x=p[x]]=true) ++t;
        while (t>1) {
            int ct=0;
            int cd;
            for (cd=d[t]; d[t]==cd; t/=cd) ++ct;
            mv[cd]=max(mv[cd],ct);
        }
    }
    long long tot=1;
    for (int i=2; i<=n; ++i) if (mv[i]) for (int j=0; j<mv[i]; ++j) tot=tot*i%MOD;
    cout << tot;
}
