// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-08 17:05:36 PST

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
    s.push_back('$');
    int n = (int) s.size();
    for (int i=0; i<n; ++i) ++nc[c[i]=int(s[i])];
    for (int i=0; i<max(n,200); ++i) ps[i+1]=ps[i]+nc[i];
    for (int i=n-1; ~i; --i) p[ps[c[i]]+(--nc[c[i]])]=i;
    int l = 31-__builtin_clz(n-1);
    rc[0]=c;
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
        rc[j+1]=c;
    }
    ll ss; cin >> ss;
    for (int i=1; i<n; ++i) {
        int x=p[i-1], y=p[i];
        int ans=0;
        for (int j=l; ~j; --j) if (rc[j][x]==rc[j][y]) {
            ans += (1<<j);
            x+=(1<<j);
            y+=(1<<j);
        }
        int ns=n-p[i]-ans-1;
        if (ss<=ns) {
            for (int j=0; j<ss+ans; ++j) cout << s[p[i]+j];
            return 0;
        }
        ss-=ns;
    }
}