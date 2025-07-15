#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")
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

int segtree[800000];

void build(int i, int l, int u) {
    segtree[i] = u-l+1;
    if (l == u) return;
    int m = (l+u)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, u);
}

void update(int i, int l, int u, int ui) {
    if (ui<l || u<ui) return;
    segtree[i]--;
    if (l==u) return;
    int m = (l+u)/2;
    update(2*i, l, m, ui);
    update(2*i+1, m+1, u, ui);
}

int walk(int i, int l, int u, int t) {
    if (l==u) return l;
    int st1 = 2*i;
    int st2 = 2*i+1;
    if (segtree[st1] < t) return walk(st2, (l+u)/2+1, u, t-segtree[st1]);
    return walk(st1, l, (l+u)/2, t);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    build(1,0,n-1);
    int cn=0;
    forn(i,n) {
        cn+=k;
        cn%=(n-i);
        int c = walk(1, 0, n-1, cn+1);
        cout << c+1 spc;
        update(1, 0, n-1, c);
    }

}