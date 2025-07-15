// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-31 10:14:01 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

ll xp(int a, int b) {
    if (!b) return 1;
    if (b&1) return xp(a,b-1)*a%MOD;
    ll t=xp(a,b>>1);
    return t*t%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    while (n--) {
        int a,b; cin >> a >> b;
        cout << xp(a,b) << '\n';
    }
}
