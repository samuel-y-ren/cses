// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-07 14:48:59 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=100005;
vector<int> c(MAXN), cn(MAXN), p(MAXN), pn(MAXN);
int nc[MAXN], ps[MAXN];
vector<int> rc[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    s.push_back('?');
    int n = (int) s.size();
    if (n==2) {
        cout << 1;
        return 0;
    }
    for (int i=0; i<n; ++i) ++nc[c[i]=int(s[i])];
    for (int i=0; i<max(n,200); ++i) ps[i+1]=ps[i]+nc[i];
    for (int i=n-1; ~i; --i) p[ps[c[i]]+(--nc[c[i]])]=i;
    int l = 31-__builtin_clz(n-1);
    ll ans = (ll)n*(n-1)/2;
    rc[0].resize(n);
    copy(c.begin(),c.end(),rc[0].begin());
    for (int j=0; j<l; ++j) {
        int bs=1<<j;

        for (int i=0; i<n; ++i) ++nc[c[i]];
        for (int i=0; i<n; ++i) ps[i+1]=ps[i]+nc[i];
        for (int i=n-1; ~i; --i) {
            int pv=(p[i]-bs+n)%n;
            pn[ps[c[pv]]+(--nc[c[pv]])]=pv;
        }
        cn[pn[0]]=0;
        for (int i=1; i<n; ++i) {
            cn[pn[i]]=cn[pn[i-1]];
            if (c[pn[i-1]] != c[pn[i]] || 
                c[(pn[i-1]+bs)%n] != c[(pn[i]+bs)%n]) ++cn[pn[i]];
        }
        swap(c,cn);
        swap(p,pn);
        rc[j+1].resize(n);
        copy(c.begin(),c.end(),rc[j+1].begin());
    }
    for (int i=1; i<n; ++i) {
        int x=p[i-1], y=p[i];
        for (int j=l; ~j; --j) if (rc[j][x]==rc[j][y]) {
            ans -= (1<<j);
            x+=(1<<j);
            y+=(1<<j);
        }
    }
    cout << ans;
}