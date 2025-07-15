// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-08 13:18:22 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = (int) s.size();
    int z[n]={};
    int l=0,r=0;
    for (int i=1; i<n; ++i) {
        if (i<r) z[i]=min(r-i,z[i-l]);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if (i+z[i]>r) {
            l=i;
            r=i+z[i];
        }
    }
    int k[n]={};
    for (int i=1; i<n; ++i) {
        int j=k[i-1];
        while (j&&s[j]!=s[i]) j=k[j-1];
        k[i]=j+(s[j]==s[i]);
    }
    for (int i : z) cout << i << ' ';
    cout << '\n';
    for (int i : k) cout << i << ' ';
    cout << '\n';
}
