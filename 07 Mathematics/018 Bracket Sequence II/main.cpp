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
    int n; string s; cin >> n >> s;
    int lc=0, rc=0;
    if (n&1) {
        cout << 0;
        return 0;
    }
    for (char c : s) {
        if (c=='(') ++lc;
        else ++rc;
        if (rc>lc) {
            cout << 0;
            return 0;
        }
    }
    int x=n/2-lc,y=lc-rc;
    if (x<0||y<0) {
        cout << 0;
        return 0;
    }
    ll nm=y+1,dn=x+y+1;
    for (int i=1; i<=2*x+y; ++i) nm=nm*i%MOD;
    for (int i=1; i<=x; ++i) dn=dn*i%MOD;
    for (int i=1; i<=x+y; ++i) dn=dn*i%MOD;
    cout << nm*inv(dn)%MOD;

}
