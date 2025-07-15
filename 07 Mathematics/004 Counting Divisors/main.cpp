// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-31 10:20:12 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int mn=1000001;
    int sv[mn]; for (int i=0; i<mn; ++i) sv[i]=0;
    for (int i=2; i<mn; i++) if (!sv[i]) for (int j=i; j<mn; j+=i) sv[j]=i;
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        int cd=-1,cn=0;
        int td=1;
        while (x>1) {
            while (sv[x]==cd) {
                x/=sv[x]; 
                ++cn;
            }
            td*=cn+1;
            cd=sv[x]; cn=0;
        }
        cout << td << '\n';
    }
}
