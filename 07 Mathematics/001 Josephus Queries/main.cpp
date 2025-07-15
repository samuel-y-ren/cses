// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-28 20:45:02 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while (q--) {
        int n,k; cin >> n >> k;
        if (n==1) {
            cout << 1 << '\n';
            continue;
        }
        --k;
        int f=1;
        bool s=1;
        int tr=0;
        int st=0;
        while (tr<n) {
            int nt=(n-tr-s+1)/2;
            if (tr+nt>k) {
                cout << f+s*(1<<st)+(k-tr)*(1<<(st+1)) << endl;
                break;
            }
            if (!s) f+=(1<<st);
            ++st;
            s^=(n-tr)&1;
            tr+=nt;
        }

    }
}
