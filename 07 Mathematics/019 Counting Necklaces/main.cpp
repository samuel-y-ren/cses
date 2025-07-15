// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-02 20:32:03 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD=1000000007;
ll xp(int a, int b) {
    ll r=1;
    for (int i=32-__builtin_clz(b); ~i; --i) {
        r=r*r%MOD;
        if (b&(1<<i)) r=r*a%MOD;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    ll tot=0;
    for (int i=1; i<=n; ++i) tot+=xp(m,gcd(i,n));
        cout << tot%MOD*xp(n,MOD-2)%MOD;
}
