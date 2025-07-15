#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define el << '\n'
#define nl cout << '\n'
#define cina(a,n) for (int i=0; i<n; i++) cin >> a[i]
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define forl(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<long long, long long>
#define pss pair<short, short>
#define MAX *max_element
#define MIN *min_element
#define rsz resize
 
struct range {
    int s;
    int e;
    int ui;
};
 
bool s1(const range& r1, const range& r2) {
    if (r1.s != r2.s) return r1.s<r2.s;
    return r1.e<r2.e;
}
 
bool s2(const range& r1, const range& r2) {
    if (r1.s != r2.s) return r1.s<r2.s;
    return r1.e>r2.e;
}
 
int st[1600000];
 
void update(int i, int l, int u, const int& ui) {
    if ((ui<l) | (ui>u)) return;
    // cout << l spc << u spc << ui el;
    ++st[i];
    if (l==u) return;
    int m = (l+u)/2;
    update(2*i, l, m, ui);
    update(2*i+1, m+1, u, ui);
}
 
int query(int i, int l, const int& u, const int& ql, const int& qu) {
    if ((u<ql) | (l>qu)) return 0;
    if ((l>=ql) & (u<=qu)) return st[i];
    int m = (l+u)/2;
    return query(2*i, l, m, ql, qu) + query(2*i+1, m+1, u, ql, qu);
}
 
vector<int> cc;
 
int bs(int l, int u, const int& t) {
    if (l==u) return l;
    int m = (l+u)/2;
    if (cc[m] < t) return bs(m+1, u, t);
    return bs(l, m, t);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    range r[n];
    vector<int> uv;
    forn(i,n) {
        cin >> r[i].s >> r[i].e;
        r[i].ui = i;
        uv.pb(r[i].s);
        uv.pb(r[i].e);
    }
    sort(uv.begin(), uv.end());
    cc.pb(uv[0]);
    forl(i, 1, 2*n) if (uv[i] != uv[i-1]) cc.pb(uv[i]);
    int m = (int) cc.size();
    // cout << m << endl;
    // sort(r,r+n,s1);
    // forn(i, n) cout << r[i].s spc << r[i].e el;
    // cout << m << endl;
    forn(i,n) {
        r[i].s = lower_bound(cc.begin(), cc.end(), r[i].s)-cc.begin();
        r[i].e = lower_bound(cc.begin(), cc.end(), r[i].e)-cc.begin();
    }
    // cout << lower_bound(cc.begin(), cc.end(), 979968588) - cc.begin() el;
    sort(r,r+n,s2);
    // forn(i, n) cout << r[i].s spc << r[i].e el;
    // cout << m << endl;
    int ans[n];
    for (int i=n-1; i>=0; i--) {
        ans[r[i].ui] = query(1, 0, m-1, 0, r[i].e);
        update(1, 0, m-1, r[i].e);
    }
    for (int i : ans) cout << i spc;
    nl;
    forn(i,4*m) st[i]=0;
    sort(r,r+n,s2);
    forn(i,n) {
        ans[r[i].ui] = query(1, 0, m-1, r[i].e, m-1);
        update(1, 0, m-1, r[i].e);
    }
    for (int i : ans) cout << i spc;
}