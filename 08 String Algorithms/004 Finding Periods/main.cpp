// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-08 14:55:36 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    int mp[n]; mp[0]=0;
    for (int i=1; i<n; ++i) {
        int j=mp[i-1];
        while (j&&s[i]!=s[j]) j=mp[j-1];
        mp[i]=j+(s[i]==s[j]);
    }
    int x=mp[n-1];
    while (x>(n+1)/2) x=mp[x-1];
    bool w[n]={};
    while (x) {
        int k=n-x;
        w[k]=true;
        int y=mp[k-1];
        while (y>=(k+1)/2) {
            if (!(k%(k-y))) {
                int z=k-y;
                if (!w[z]) for (int i=z; i<k; i+=z) w[i]=true;
                break;
            }
            y=mp[y-1];
        }
        x=mp[x-1];
    }
    vector<int> a={};
    for (int i=1; i<n; ++i) if (w[i]) a.push_back(i);
    for (int i : a) cout << i << ' ';
    cout << n;
}
