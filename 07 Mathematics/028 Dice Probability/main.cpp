// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-04 17:17:06 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b; cin >> n >> a >> b;
    double p[6*n+1]={}; p[0]=1;
    for (int i=1; i<=n; ++i) for (int j=6*i; ~j; --j) {
        p[j]=0;
        for (int k=max(0,j-6); k<j; ++k) p[j]+=p[k];
        p[j]/=6;
    }
    double t=0;
    for (int i=a; i<=b; ++i) t+=p[i];
    cout << fixed << setprecision(6) << t;
}
