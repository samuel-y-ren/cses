// File: 1654.cpp
// Author: Samuel Ren
// Created: 2026-06-05 14:18:49 EST

#include <bits/stdc++.h>
using namespace std;

const int b=20;
const int mn=(1<<b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int x[n];
    int o[mn]={};
    for (int i=0; i<n; ++i) {
        cin >> x[i];
        ++o[x[i]];
    }
    int o2[mn];
    for (int i=0; i<mn; ++i) {
        o2[i] = o[i];
    }
    for (int j=0; j<b; ++j) {
        int s = (1<<j);
        for (int i=0; i<mn; i+=(2<<j)) {
            for (int k=0; k<s; ++k) o[i+k+s] += o[i+k];
        }
        for (int i=0; i<mn; i+=(2<<j)) {
            for (int k=0; k<s; ++k) o2[i+k] += o2[i+k+s];
        }
    }
    for (int i=0; i<n; ++i) {
        cout << o[x[i]] << ' ' << o2[x[i]] << ' ' << n - o[x[i] ^ (mn-1)] << '\n';
    }
}
