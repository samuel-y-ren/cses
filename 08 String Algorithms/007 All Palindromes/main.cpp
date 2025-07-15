// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-04 08:44:59 PST

#include <bits/stdc++.h>
using namespace std;

inline void smax(int& a, int b) {
    if (b>a) a=b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    int p[n]; for (int i=0; i<n; ++i) p[i]=1;
    int l=-1, r=0;
    int op[n];
    for (int i=0; i<n; ++i) {
        op[i] = (i>=r ? 0 : min(r-i,op[l+r-i]));
        while (~(i-op[i]) && i+op[i]<n && s[i-op[i]]==s[i+op[i]]) ++op[i];
        if (i+op[i]>r) {
            l=i-op[i]; r=i+op[i];
        }
        smax(p[i+op[i]-1], op[i]*2-1);
    }
    int ep[n];
    ep[0]=0;
    l=0; r=0;
    for (int i=1; i<n; ++i) {
        ep[i] = (i>=r ? 0 : min(r-i,ep[l+r-i+1]));
        while (~(i-ep[i]-1) && i+ep[i]<n && s[i-ep[i]-1]==s[i+ep[i]]) ++ep[i];
        if (i+ep[i]>r) {
            l=i-ep[i]-1; r=i+ep[i];
        }
        smax(p[i+ep[i]-1], ep[i]*2);
    }
    int mv=-1000000;
    for (int i=n-1; ~i; --i) {
        smax(mv,p[i]-2*i);
        smax(p[i],mv+2*i);
    }
    for (int i=0; i<n; ++i) cout << p[i] << ' ';
}