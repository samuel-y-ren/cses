// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-11 17:46:16 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segt {
    vector<int> st;
    int n;
    segt(int n_) : n(n_) {
        st.resize(2*n,0);
    }
    void upd(int id, int d) {
        for (id+=n; id; id>>=1) st[id]+=d;
    }
    int qr(int l, int r) {
        int t=0;
        for (l+=n,r+=n; l<r; l>>=1,r>>=1) {
            if (l&1) t+=st[l++];
            if (r&1) t+=st[--r];
        }
        return t;
    }

};

const int MAXN = 1000005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pair<int,int>> v[MAXN*2];
    vector<pair<int,int>> h[MAXN*2];
    for (int i=0; i<n; ++i) {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        x1+=MAXN; y1+=MAXN; x2+=MAXN; y2+=MAXN;
        if (x1==x2) h[x1].emplace_back(y1,y2);
        else {
            v[x1].emplace_back(y1,1);
            v[x2].emplace_back(y2,-1);
        }
    }
    segt st(MAXN*2);
    ll t=0;
    for (int i=0; i<MAXN*2; ++i) {
        for (auto& j : h[i]) t+=st.qr(j.first,j.second);
        for (auto& j : v[i]) st.upd(j.first,j.second);
    }
    cout << t;
}
