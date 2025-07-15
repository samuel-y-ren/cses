// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-01 20:24:13 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    s = s+s;
    int n = s.size();
    int f[n]={-1};
    int k = 0;
    for (int i=1; i<n; ++i){
        char c = s[i];
        int t = f[i-k-1];
        while(~t && c!=s[t+k+1]){
            if (c<s[t+k+1]) k = i-t-1;
            t = f[t];
        }

        if (c!=s[k+t+1]) {
            if(c < s[k]) k = i;
            f[i-k] = -1;
        } 
        else f[i-k] = t+1;
    }
    for (int i=k; i<n/2+k; ++i) cout << s[i];
}
