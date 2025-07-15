// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-04 09:07:58 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD=1000000007;
const int IP=1000000005;
ll inv(int a) {
    ll r=1;
    for (int i=29; ~i; --i) {
        r=r*r%MOD;
        if (IP&(1<<i)) r=r*a%MOD;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<ll> mt[n];
    for (int i=0; i<n; ++i) {
        mt[i].resize(m+1);
        for (int j=0; j<=m; ++j) cin >> mt[i][j];
    }
    for (int i=0; i<min(n,m); ++i) {
        if (!mt[i][i]) {
            bool f=false;
            for (int j=i+1; j<n; ++j) if (mt[j][i]) {
                f=true;
                swap(mt[i],mt[j]);
                break;
            }
            if (!f) continue;
        }
        for (int j=i+1; j<n; ++j) {
            ll mp=MOD-mt[j][i]*inv(mt[i][i])%MOD;
            if (!mp) continue;
            for (int k=i; k<=m; ++k) mt[j][k]=(mt[j][k]+mt[i][k]*mp)%MOD;
        }
    }
    for (int i=m; i<n; ++i) if (mt[i][m]) {
        cout << -1;
        return 0;
    }
    int v[m];
    for (int i=n; i<m; ++i) v[i]=1;
    for (int i=min(n,m)-1; ~i; --i) {
        v[i]=mt[i][m];
        for (int j=i+1; j<m; ++j) v[i]=(v[i]-mt[i][j]*v[j]%MOD+MOD)%MOD;
        if (v[i]&&!mt[i][i]) {
            cout << -1;
            return 0;
        }
        if (!mt[i][i]&&!v[i]) v[i]=0;
        else v[i]=v[i]*inv(mt[i][i])%MOD;
    }
    for (int i : v) cout << i << ' ';
}
