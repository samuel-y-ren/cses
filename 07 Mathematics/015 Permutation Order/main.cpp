// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-02 19:06:50 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll p[20];
    p[0]=1;
    for (int i=1; i<20; ++i) p[i]=p[i-1]*i;
    int t; cin >> t;
    while (t--) {
        int qt; cin >> qt;
        if (qt==1) {
            int n; ll k; cin >> n >> k;
            --k;
            bool u[n+1]={};
            for (int i=n-1; ~i; --i) {
                int tn=k/p[i]+1;
                for (int j=1; j<=n; ++j) {
                    if (!u[j] && !--tn) {
                        u[j]=true;
                        cout << j << ' ';
                        break;
                    }
                }
                k%=p[i];
            }
            cout << '\n';
        }
        else {
            int n; cin >> n;
            ll o=1;
            bool u[n+1]={};
            for (int i=0; i<n; ++i) {
                int x; cin >> x;
                int ct=0;
                for (int j=1; j<x; ++j) if (!u[j]) ++ct;
                u[x]=true;
                o+=ct*p[n-i-1];
            }
            cout << o << '\n';
        }

    }
}
