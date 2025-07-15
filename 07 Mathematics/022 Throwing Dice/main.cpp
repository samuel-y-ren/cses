// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-03 20:24:33 PST

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
    ll n; cin >> n;
    vector<ll> o={0,0,0,0,0,1};
    sm b({
{0,1,0,0,0,0},
{0,0,1,0,0,0},
{0,0,0,1,0,0},
{0,0,0,0,1,0},
{0,0,0,0,0,1},
{1,1,1,1,1,1},});
    sm c=b;
    for (int i=0; i<61; ++i) {
        if (n&(1ll<<i)) o = c*o;
        c=c*c;
    }
    cout << o[5];
}
