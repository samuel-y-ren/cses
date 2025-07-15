// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-31 10:16:47 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M1=1000000006;
const int M2=1000000007;

ll p1(int a, int b) {
    if (!b) return 1;
    if (b&1) return p1(a,b-1)*a%M1;
    ll t=p1(a,b>>1);
    return t*t%M1;
}

ll p2(int a, int b) {
    if (!b) return 1;
    if (b&1) return p2(a,b-1)*a%M2;
    ll t=p2(a,b>>1);
    return t*t%M2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    while (n--) {
        int a,b,c; cin >> a >> b >> c;
        cout << p2(a,p1(b,c)) << '\n';
    }
}
