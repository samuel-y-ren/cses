// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-03 20:07:40 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD=1000000007;

map<ll,ll> f;
ll fib(ll n) {
    if (f.find(n)==f.end()) {
        if (n&1) f[n]=fib(n/2)*(fib(n/2-1)+fib(n/2+1))%MOD;
        else {
            ll x=fib(n/2),y=fib(n/2-1);
            f[n]=(x*x+y*y)%MOD;
        }
    }    
    return f[n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f[0]=f[1]=1;
    ll n; cin >> n;
    if (!n) cout << 0;
    else cout << fib(n-1);
}
