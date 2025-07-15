// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-02 19:48:35 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD=1000000007;
const int M2=1000000005;
ll inv(int a) {
    ll r=1;
    for (int i=30; ~i; --i) {
        r=r*r%MOD;
        if (M2&(1<<i)) r=r*a%MOD;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    if (n&1) {
        cout << 0;
        return 0;
    }
    n/=2;
    ll nm=1,dn=n+1;
    for (int i=1; i<=2*n; ++i) nm=nm*i%MOD;
    for (int i=1; i<=n; ++i) dn=dn*i%MOD*i%MOD;
    cout << nm*inv(dn)%MOD;

}
