// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-03 20:50:09 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD=1000000007;

struct sm {
    vector<vector<ll>> m;
    int n;
    sm(vector<vector<ll>> m): m(m) {
        n = m.size();
    } 
    sm(int n): n(n) {
        m.resize(n);
        for (auto &i : m) i.resize(n,0);
    }
    sm operator*(const sm& other) const {
        sm r(n);
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) for (int k=0; k<n; ++k) r.m[i][j]=(r.m[i][j]+m[i][k]*other.m[k][j])%MOD;
        return r;
    }
    vector<ll> operator*(const vector<ll>& other) const {
        vector<ll> r(n);
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) r[i]=(r[i]+m[i][j]*other[j])%MOD;
        return r;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k; cin >> n >> m >> k;
    sm b(n);
    for (int i=0; i<m; ++i) {
        int x, y; cin >> x >> y;
        ++b.m[y-1][x-1];
    }
    vector<ll> r(n,0);
    r[0]=1;
    sm c=b;
    for (int i=0; i<30; ++i) {
        if (k&(1<<i)) r=c*r;
        c=c*c;
    }
    cout << r[n-1];
}
