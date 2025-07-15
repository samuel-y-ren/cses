// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-23 19:04:00 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize("Ofast")
inline int lg(int x) {
    return 31-__builtin_clz(x);
}

typedef array<int,30> arr;

const int MAXL = 30;

class segt{
private:
    vector<arr> st;
    const vector<int> &x;
    const vector<int> &o;
    int n;
    void ini() {
        for (int i=0; i<n; ++i) for (int j=0; j<MAXL; ++j) st[i+n][j]=2000000000;
        for (int i=0; i<n; ++i) st[i+n][o[i]]=x[i];
        for (int i=n-1; i>0; --i) for (int j=0; j<MAXL; ++j) st[i][j] = min(st[i<<1][j],st[(i<<1)|1][j]);
    }
public:
    segt(int n, const vector<int> &x, const vector<int> &o) : n(n), x(x), o(o) {
        st.resize(2*n);
        ini();
    }
    arr qu(int l, int r) {
        arr ret;
        for (int i=0; i<MAXL; i++) ret[i]=2000000000;
        for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) {
                for (int j=0; j<MAXL; ++j) ret[j]=min(ret[j],st[l][j]);
                ++l;
            }
            if (r&1) {
                --r;
                for (int j=0; j<MAXL; ++j) ret[j]=min(ret[j],st[r][j]);
            }
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    vector<int> x(n), o(n); 
    for (int i=0; i<n; i++) {
        cin >> x[i];
        o[i]=lg(x[i]);
    }
    segt st(n,x,o);
    ll ps[MAXL][n+1];
    for (int i=0; i<MAXL; i++) ps[i][0]=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<MAXL; j++) ps[j][i+1]=ps[j][i];
        ps[o[i]][i+1]+=x[i];
    }
    while (q--) {
        int a,b; cin >> a >> b;
        a--;
        bool f = 0;
        arr ret=st.qu(a,b);
        ll t=0;
        for (int i=0; i<MAXL; ++i) {
            if (t<(1<<(i+1))-1&&ret[i]>t+1) {
                cout << t+1 << '\n';
                f=1;
                break;
            }
            t+=ps[i][b]-ps[i][a];
        }
        if (!f) cout << t+1 << '\n';
    }
}