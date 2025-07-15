// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-04 08:17:15 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    int l=-1, r=0;
    int op[n];
    for (int i=0; i<n; ++i) {
        op[i] = (i>=r ? 0 : min(r-i,op[l+r-i]));
        while (~(i-op[i]) && i+op[i]<n && s[i-op[i]]==s[i+op[i]]) ++op[i];
        if (i+op[i]>r) {
            l=i-op[i]; r=i+op[i];
        }
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
    }
    int lp=0, li; bool o=true;
    for (int i=0; i<n; ++i) {
        int x;
        if ((x=2*op[i]-1)>lp) {
            lp=x; li=i;
        }
    }
    for (int i=1; i<n; ++i) {
        int x;
        if ((x=2*ep[i])>lp) {
            lp=x; li=i; o=false;
        }
    }
    if (o) for (int i=li-op[li]+1; i<li+op[li]; ++i) cout << s[i];
    else for (int i=li-ep[li]; i<li+ep[li]; ++i) cout << s[i];
}
