// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-08 11:21:51 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    int mp[n]; mp[0]=0;
    for (int i=1; i<n; ++i) {
        int j = mp[i-1];
        while (j&&s[j]!=s[i]) j=mp[j-1];
        mp[i]=j+(s[j]==s[i]);
    }
    vector<int> a;
    int x=mp[n-1];
    while (x) {
        a.push_back(x);
        x=mp[x-1];
    }
    for (int i=(int)a.size()-1;~i;--i) cout << a[i] << ' ';
}
