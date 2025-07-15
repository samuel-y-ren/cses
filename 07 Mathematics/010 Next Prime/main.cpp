// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-01 21:34:28 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int mn=1000000;
    bool ic[mn]={};
    vector<int> p;
    for (int i=2; i<mn; ++i) if (!ic[i]) {
        for (int j=2*i; j<mn; j+=i) ic[j]=true;
        p.push_back(i);
    }
    int t; cin >> t;
    while (t--) {
        ll x; cin >> x;
        bool f=false;
        while (!f) {
            ++x;
            f=true;
            for (int i : p) {
                if (i*i>x) break;
                if (!(x%i)) {
                    f=false;
                    break;
                }
            }
        }
        cout << x << '\n';
    }
}
