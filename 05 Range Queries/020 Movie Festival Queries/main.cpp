// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-19 21:56:32 PST

#include <bits/stdc++.h>
using namespace std;

const int MAXL = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    int t[2*n];
    pair<int,int> mt[n];
    for (int i=0; i<n; i++) {
        cin >> mt[i].first >> mt[i].second;
        t[2*i]=mt[i].first;
        t[2*i+1]=mt[i].second;
    }
    sort(t,t+2*n);
    int nm[2*n];
    int sm[2*n];
    for (int i=0; i<2*n; i++) {
        nm[i]=2*n;
        sm[i]=2000000000;
    }
    for (auto &i : mt) {
        int v = lower_bound(t,t+2*n,i.first)-t;
        nm[v]=min(nm[v],(int)(lower_bound(t,t+2*n,i.second)-t));
        sm[v]=min(sm[v],i.second);
    }
    int cnm=2*n;
    vector<int> bl[2*n+1];
    int nsm[2*n+1];
    nsm[2*n]=2000000000;
    for (int i=2*n-1; i>=0; i--) {
        cnm = min(cnm,nm[i]);
        bl[i].push_back(cnm);
        nsm[i]=min(nsm[i+1],sm[i]);
    }
    for (int s=1; s<MAXL; s++) {
        for (int i=2*n-1; i>=0; i--) {
            if (bl[i].size()>=s && bl[bl[i][s-1]].size()>=s) bl[i].push_back(bl[bl[i][s-1]][s-1]);
        }
    }
    while (q--) {
        int a,b; cin >> a >> b;
        int cm=lower_bound(t,t+2*n,a)-t;
        int em=upper_bound(t,t+2*n,b)-t-1;
        int tm=0;
        for (int i=MAXL-1; i>=0; i--) {
            if (bl[cm].size()<i+1) continue;
            if (bl[cm][i]>em) continue;
            tm += (1<<i);
            cm = bl[cm][i];
        }
        cout << tm + (nsm[cm]<=b) << '\n';
    }
}
