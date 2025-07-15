// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-08 14:13:08 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int s[n];
    int si[n+1];
    for (int i=0; i<n; ++i) {
        cin >> s[i]; 
        si[--s[i]]=i+1;
    }
    si[n]=0;
    int r[n]={};
    int pv=si[s[0]+1];
    for (int i=1; i<n; ++i) {
        r[s[i]]=r[s[i-1]];
        if (si[s[i]+1]<pv) ++r[s[i]];
        pv=si[s[i]+1];
    }
    if (r[s[n-1]]>25) {
        cout << -1;
        return 0;
    }
    for (int i=0; i<n; ++i) cout << char(r[i]+97);
}
