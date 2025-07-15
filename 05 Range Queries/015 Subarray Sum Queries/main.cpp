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
#define rsz resize
 
int x[200000];
 
struct node {
    ll l;
    ll r;
    ll s;
    ll m;
};
 
node merge(node& n1, node& n2) {
    node nn;
    nn.s = n1.s + n2.s;
    nn.l = max(n1.s + n2.l, n1.l);
    nn.r = max(n2.s + n1.r, n2.r);
    nn.m = max(max(n1.m, n2.m), n1.r + n2.l);
    return nn;
}
 
node st[800000];
 
void build(int i, int l, int r) {
    if (l==r) {
        st[i].l = max(x[l], 0);
        st[i].r = st[i].l;
        st[i].m = st[i].l;
        st[i].s = x[l];
        return;
    }
    int st1 = 2*i, st2 = 2*i+1;
    int m = (l+r)/2;
    build(st1, l, m);
    build(st2, m+1, r);
    st[i] = merge(st[st1], st[st2]);
}
 
void update(int i, int l, int r, int ui, int uv) {
    if (ui < l || ui > r) return;
    if (l==r) {
        st[i].l = max(x[l], 0);
        st[i].r = st[i].l;
        st[i].m = st[i].l;
        st[i].s = x[l];
        return;
    }
    int st1 = 2*i, st2 = 2*i+1;
    int m = (l+r)/2;
    update(st1, l, m, ui, uv);
    update(st2, m+1, r, ui, uv);
    st[i] = merge(st[st1], st[st2]);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int n, q; cin >> n >> q;
    cina(x,n);
    build(1, 0, n-1);
    forn(qn, q) {
        int i, v; cin >> i >> v;
        i--;
        x[i] = v;
        update(1, 0, n-1, i, v);
        cout << st[1].m el;
    }
}