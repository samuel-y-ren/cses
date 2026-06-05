// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-14 20:03:24 PST
 
#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    int b[n]={};
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        for (int j=0; j<k; ++j) if (s[j]=='1') b[i]+=(1<<j);
    }
    int t=k;
    for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) if (__builtin_popcount(b[i]^b[j])<t) t=__builtin_popcount(b[i]^b[j]);
    cout << t;
}