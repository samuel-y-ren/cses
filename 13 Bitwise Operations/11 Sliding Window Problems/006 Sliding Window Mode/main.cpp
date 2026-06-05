// File: main.cpp
// Author: Samuel Ren
// Created: 2025-11-14 17:17:50 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    int a[n]; for (int i=0; i<n; ++i) cin >> a[i];
    map<int, int> s;
    set<pair<int,int>> m;
    for (int i=0; i<k; ++i) {
        if (s.find(a[i]) == s.end()) {
            s[a[i]]=1;
            m.insert({-1,a[i]});
        }
        else {
            int& x=s[a[i]];
            m.erase({-x,a[i]});
            ++x;
            m.insert({-x,a[i]});
        }
    }
    cout << (*m.begin()).second << ' ';
    for (int i=k; i<n; ++i) {
        if (!--s[a[i-k]]) {
            m.erase({-1,a[i-k]});
            s.erase(a[i-k]);
        }
        else {
            m.erase({-s[a[i-k]]-1,a[i-k]});
            m.insert({-s[a[i-k]],a[i-k]});
        }
        if (s.find(a[i]) == s.end()) {
            s[a[i]]=1;
            m.insert({-1,a[i]});
        }
        else {
            int& x = s[a[i]];
            m.erase({-x,a[i]});
            ++x;
            m.insert({-x,a[i]});
        }
        cout << (*m.begin()).second << ' ';
    }
}
