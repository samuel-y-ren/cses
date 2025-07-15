// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-08 16:50:00 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = (int) s.size();
    int ci[n];
    int c[26]={};
    int x=0;
    for (int i=0; i<n; ++i) {
        if (s[i] != '#') ++c[ci[i]=int(s[i])-97];
        else x=i;
    }
    int ps[26]; ps[0]=0; 
    for (int i=0; i<25; ++i) ps[i+1]=ps[i]+c[i];
    int nx[n];
    for (int i=n-1; ~i; --i) if (s[i]!='#') nx[ps[ci[i]]+(--c[ci[i]])+1]=i;
    for (int i=1; i<n; ++i) {
        x=nx[x];
        cout << s[x];
    }
}
