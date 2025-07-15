// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-08 11:15:00 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x,t; cin >> x >> t;
    string s=t+"#"+x;
    int n = s.size();
    int mp[n+1]; mp[0]=0;
    for (int i=1; i<n; ++i) {
        int j = mp[i-1];
        while (j&&s[i]!=s[j]) j=mp[j-1];
        mp[i]=j+(s[i]==s[j]);
    }
    int a=0;
    for (int i=t.size()+1; i<n; ++i) if (mp[i]==t.size()) ++a;
    cout << a;
}
