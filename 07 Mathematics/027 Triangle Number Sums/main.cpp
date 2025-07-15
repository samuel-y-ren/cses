// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-04 10:57:02 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mn=1000000000001;
const int bb=15;
const int ms=1<<(2*bb);
const int b=1<<bb;
bitset<ms> s;
short l[(mn>>bb)+1];

inline bool itn(ll x) {
    if (x<ms) return s[x];
    return (((x&(b-1))==(l[x>>bb]&(b-1)))&&l[x>>bb]&b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ct=1;
    for (int i=1; ct<=mn; ct+=++i) {
        if (ct<ms) s[ct]=1;
        else l[ct>>bb]=(ct&(b-1))|b;
    }
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        if (itn(n)) cout << 1 << '\n';
        else {
            bool f=false;
            ll ct=1;
            for (int i=1; ct<n; ct+=++i) {
                if (itn(n-ct)) {
                    f=true;
                    break;
                }
            }
            cout << (f?2:3) << '\n';
        }
    }
}
