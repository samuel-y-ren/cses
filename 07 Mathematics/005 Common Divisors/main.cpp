// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-31 10:33:00 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int mn=1000001;
    vector<int> d[mn];
    for (int i=2; i<mn; i++) if (!d[i].size()) for (int j=i; j<mn; j+=i) d[j].push_back(i);
    int n; cin >> n;
    bool f[mn]={};
    int v[mn]={};
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        if (v[x]) f[x]=1;
        else v[x]=x;
    }
    for (int i=mn-1; i>=0; i--) {
        if (!v[i]) continue;
        if (f[i]) {
            cout << i << '\n';
            return 0;
        }
        for (int j : d[i]) {
            if (v[i/j]&&v[i/j]!=v[i]) f[i/j]=1;
            else v[i/j]=v[i];
        }
    }
}
