// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-31 10:43:07 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    ll t=0;
    const int b=1000000;
    for (int i=1; n/i>b; ++i) t+=(n/i)*i;
    for (int i=b; i>0; --i) t+=i*((n/i+n/(i+1)+1)%MOD)%MOD*((n/i-n/(i+1))%MOD)%MOD*((MOD+1)/2)%MOD;
    cout << t%MOD;
}
