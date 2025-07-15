// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-04 10:29:33 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mn=10000001;
    pair<bool,pair<int,int>> p[mn];
    for (int i=0; i*i<mn; ++i) {
        mn-=i*i;
        for (int j=0; j*j<mn; ++j) p[i*i+j*j]={true,{i,j}};
        mn+=i*i;
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool f=false;
        for (int i=0; i*i<=n; ++i) {
            n-=i*i;
            for (int j=0; j*j<=n; ++j) if (p[n-j*j].first) {
                cout << i << ' '  << j << ' ' << p[n-j*j].second.first << ' ' << p[n-j*j].second.second << '\n';
                f=true;
                break;
            }
            if (f) break;
            n+=i*i;
        }
    }
}
