// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-11 15:05:25 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void smin(ll& a, ll b) {
    if (b<a) a=b;
}

inline void smax(ll& a, ll b) {
    if (a<b) a=b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll mins=INT_MAX,maxs=(1<<31),mind=INT_MAX,maxd=(1<<31);
    while (n--) {
        ll x,y; cin >> x >> y;
        smin(mins,x+y);
        smax(maxs,x+y);
        smin(mind,x-y);
        smax(maxd,x-y);
        cout << max(maxs-mins,maxd-mind) << '\n';
    }
}
