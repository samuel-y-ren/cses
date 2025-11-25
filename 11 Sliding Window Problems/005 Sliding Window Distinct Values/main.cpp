// File: main.cpp
// Author: Samuel Ren
// Created: 2025-11-14 17:11:28 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    int a[n]; for (int i=0; i<n; ++i) cin >> a[i];
    map<int, int> s;
    for (int i=0; i<k; ++i) {
        if (s.find(a[i]) == s.end()) s[a[i]]=1;
        else ++s[a[i]];
    }
    cout << s.size() << ' ';
    for (int i=k; i<n; ++i) {
        if (!--s[a[i-k]]) s.erase(a[i-k]);
        if (s.find(a[i]) == s.end()) s[a[i]]=1;
        else ++s[a[i]];
        cout << s.size() << ' ';
    }
}
