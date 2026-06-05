// File: main.cpp
// Author: Samuel Ren
// Created: 2026-02-08 14:38:57 EST

#include <bits/stdc++.h>
using namespace std;

const int mn=200005;
int t[mn*2];
int n;

inline void on(int idx) {
    for (t[idx+=n]=1; idx>1; idx>>=1) ++t[idx>>1];
}

inline int q(int l, int r) {
    int res=0;
    for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k; cin >> n >> k;
    pair<int,int> v[n];
    for (int i=0; i<n; ++i) {
        cin >> v[i].first;
        v[i].second=i;
    }
    sort(v, v+n);
    int ii[n], oi[n];
    for (int i=0; i<n; ) {
        int ev;
        for (int j=i; (j<n && v[j].first==v[i].first) || !(~(ev=j)); ++j) {
            int idx=v[j].second;
            oi[idx]=q(idx, min(n, idx+k));
        }
        for (int j=i; j<ev; ++j) on(v[j].second);
        for (int j=i; j<ev; ++j) {
            int idx=v[j].second;
            ii[idx]=idx-max(0, idx-k+1)-q(max(0, idx-k+1), idx);
        }
        i=ev;
    }
    long long inv=0;
    for (int i=0; i<k; ++i) inv += ii[i];
    cout << inv << ' ';
    for (int i=k; i<n; ++i) {
        inv+=ii[i];
        inv-=oi[i-k];
        cout << inv << ' ';
    }
}
