// File: main.cpp
// Author: Samuel Ren
// Created: 2025-11-14 16:30:57 EST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    int x,a,b,c; cin >> x >> a >> b >> c;
    pair<int,int> stk[n];
    stk[0]={x,0};
    int l=0,r=0;
    for (int i=1; i<k; ++i) {
        x=((ll)x*a+b)%c;
        while (l<=r&&x<=stk[r].first) --r;
        stk[++r]={x,i};
    }
    ll e=stk[0].first;
    for (int i=k; i<n; ++i) {
        x=((ll)x*a+b)%c;
        while (l<=r&&x<=stk[r].first) --r;
        stk[++r]={x,i};
        if (stk[l].second==i-k) ++l;
        e ^= stk[l].first;
    }
    cout << e;
}
