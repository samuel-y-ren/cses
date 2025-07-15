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
#define MAX *max_element
#define MIN *min_element

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct range {
    int s;
    int e;
    int ui;
};

bool s1(range r1, range r2) {
    if (r1.s != r2.s) return r1.s<r2.s;
    return r1.e<r2.e;
}

bool s2(range r1, range r2) {
    if (r1.s != r2.s) return r1.s<r2.s;
    return r1.e>r2.e;
}

// int st[1600000];

// int ui;

// void update(int i, int l, int u) {
//     if ((ui<l) | (ui>u)) return;
//     // cout << l spc << u spc << ui el;
//     ++st[i];
//     if (l==u) return;
//     int m = (l+u)/2;
//     update(2*i, l, m);
//     update(2*i+1, m+1, u);
// }

// int query(int i, int l, int u, int ql, int qu) {
//     if ((u<ql) | (l>qu)) return 0;
//     if ((l>=ql) & (u<=qu)) return st[i];
//     int m = (l+u)/2;
//     return query(2*i, l, m, ql, qu) + query(2*i+1, m+1, u, ql, qu);
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    range r[n];
    set<int> uv;
    forn(i,n) {
        cin >> r[i].s >> r[i].e;
        r[i].ui = i;
        uv.insert(r[i].s);
        uv.insert(r[i].e);
    }
    map<int, int> cc;
    int m = uv.size();
    auto ptr = uv.begin();
    forn(i,m) {
        cc[*ptr]=i;
        ptr++;
    }
    forn(i,n) {
        r[i].s = cc[r[i].s];
        r[i].e = cc[r[i].e];
    }
    sort(r,r+n,s1);
    int ans[n];
    ordered_set t;
    for (int i=n-1; i>=0; i--) {
        // cout << r[i].s spc << r[i].e spc << query(1, 0, m-1, 0, r[i].e) el;
        ans[r[i].ui] = t.order_of_key(r[i].e+1);
        t.insert(r[i].e);
        // update(1, 0, m-1);
        // forn(i,4*m) cout << st[i] spc;
        // nl;
    }
    for (int i : ans) cout << (bool) i spc;
    nl;
    // forn(i,4*m) st[i]=0;
    t.clear();
    sort(r,r+n,s2);
    forn(i,n) {
        ans[r[i].ui] = t.size()-t.order_of_key(r[i].e);
        t.insert(r[i].e);
        // ui = r[i].e;
        // update(1, 0, m-1);
    }
    for (int i : ans) cout << (bool) i spc;
}