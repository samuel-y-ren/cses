// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-14 20:19:08 PST
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    vector<int> id[k][n];
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        for (int j=0; j<n; ++j) id[int(s[j])-65][i].emplace_back(j);
    }
    bitset<(3000<<12)> b; 
    for (int i=0; i<k; ++i) {
        b.reset();
        bool f=false;
        for (auto& j : id[i]) {
            int l=j.size();
            for (int i1=0; i1<l; ++i1) {
                for (int i2=i1+1; i2<l; ++i2) {
                    if (b[(j[i1]<<12)+j[i2]]) {
                        f=true;
                        break;
                    }                    
                    b[(j[i1]<<12)+j[i2]]=1;
                }
                if (f) break;
            }
            if (f) break;
        }
        cout << (f ? "YES\n" : "NO\n");
    }
}