// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-04 11:04:08 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=29;
const int MOD=1000000009;
const int MAXN = 200005;
ll pp[MAXN], ip[MAXN];

struct segt {
    int n;
    string s;
    vector<ll> st;
    segt(string se) : s(se) {
        n = s.size();
        st.resize(2*n);
        for (int i=0; i<n; ++i) st[i+n]=(int(s[i])-96)*pp[i]%MOD;
        for (int i=n-1; ~i; --i) st[i]=(st[i<<1]+st[(i<<1)|1])%MOD;
    }
    ll query(int l, int r) {
        ll t=0;
        int il=l;
        for (l+=n,r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) t+=st[l++];
            if (r&1) t+=st[--r];
        }
        t%=MOD;
        t=t*ip[il]%MOD;
        return t;
    }
    void upd(int i, char c) {
        ll d=(c-s[i]+MOD)*pp[i]%MOD;
        s[i]=c;
        for (i+=n; i; i>>=1) st[i]=(st[i]+d)%MOD;
    }
};

ll inv(int x) {
    ll t=1;
    for (int i=30; ~i; --i) {
        t=t*t%MOD;
        if ((1<<i)&(MOD-2)) t=t*x%MOD;
    }
    return t;
}

void po(int n) {
    pp[0]=1;
    for (int i=1; i<n; ++i) pp[i]=pp[i-1]*p%MOD;
    ip[n-1]=inv(pp[n-1]);
    for (int i=n-1; i; --i) ip[i-1]=ip[i]*p%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    po(n);
    string s; cin >> s;
    string rs=s; reverse(rs.begin(), rs.end());
    segt ft(s), rt(rs);
    while (m--) {
        int qt; cin >> qt;
        if (qt==1) {
            int k; char x; cin >> k >> x;
            ft.upd(k-1,x);
            rt.upd(n-k,x);
        }
        else {
            int a,b; cin >> a >> b;
            cout << (ft.query(a-1, b-1)==rt.query(n-b,n-a) ? "YES\n" : "NO\n");
        }
    }
}
