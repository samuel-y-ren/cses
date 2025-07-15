// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-08 17:19:22 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=100005;
vector<int> c(MAXN), cn(MAXN), p(MAXN), pn(MAXN);
int nc[MAXN], ps[MAXN];
vector<int> rc[20];

struct rg {
    int l,r,s;
    inline int cap(int i) {
        return ((ll)r-l)*(s-i+1);
    }
    rg(int l_, int r_, int s_) : l(l_), r(r_), s(s_) {

    }
};

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

    vector<rg> stk;
    stk.emplace_back(-1,-1,-1);
    vector<rg> mf[n];
    for (int i=n-1; i; --i) {
        int x=p[i-1], y=p[i];
        int ans=0;
        for (int j=l; ~j; --j) if (rc[j][x]==rc[j][y]) {
            ans+=(1<<j);
            x+=(1<<j);
            y+=(1<<j);
        }
        while (stk.back().l>=ans) {
            mf[i].emplace_back(stk.back());
            stk.pop_back();
        }
        if (stk.back().r>ans) {
            mf[i].emplace_back(stk.back());
            mf[i].back().l=ans;
            stk.back().r=ans;
        }
        int sl=n-p[i]-1;
        if (stk.back().r<ans) stk.emplace_back(stk.back().r,ans,i);
        reverse(mf[i].begin(), mf[i].end());
        if (!mf[i].size()) mf[i].emplace_back(ans,sl,i);
        else if (mf[i].back().r<sl) mf[i].emplace_back(mf[i].back().r,sl,i);

    }

    ll ss; cin >> ss;
    for (int i=1; i<n; ++i) {
        for (auto& j : mf[i]) {
            ll x=j.cap(i);
            if (ss<=x) {
                int ln=(ss-1)/(j.s-i+1)+j.l+1;
                for (int k=0; k<ln; ++k) cout << s[p[i]+k];
                return 0;
            }
            ss-=x;
        }
    }
    cout << ss << endl;
}