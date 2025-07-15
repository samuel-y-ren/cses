// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-02 20:39:40 PST

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
    ll n; cin >> n;
    cout << (xp(2,n*n%(MOD-1))+2*xp(2,n*n/4%(MOD-1)+(n&1))+xp(2,n*n/2%(MOD-1)+(n&1)))%MOD*xp(4,MOD-2)%MOD;;
}
