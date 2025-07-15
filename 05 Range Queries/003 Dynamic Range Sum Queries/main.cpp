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
 
ll st[800000];
int a[200000];
int n;
 
void build(int i, int l, int u) {
    if (l==u) {
        st[i] = a[l];
        return;
    }
    int m = (l+u)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, u);
    st[i] = st[2*i] + st[2*i+1];
}
 
ll query(int i, int rl, int ru, int ql, int qu) {
    if (rl > qu || ql > ru) return 0;
    if (ql <= rl && ru <= qu) return st[i];
    int m = (rl + ru)/2;
    return query(2*i, rl, m, ql, qu) + query(2*i+1, m+1, ru, ql, qu);
}
 
void update(int i, int rl, int ru, int qi, int qv) {
    if (rl > qi || ru < qi) return;
    if (rl == ru) {
        st[i] = qv;
        return;
    }
    int m = (rl+ru)/2;
    update(2*i, rl, m, qi, qv);
    update(2*i+1, m+1, ru, qi, qv);
    st[i] = st[2*i] + st[2*i+1];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> n >> q;
    cina(a,n);
    build(1, 0, n-1);
    int qt, a, b;
    forn(qn, q) {
        cin >> qt >> a >> b;
        if (qt==1) {
            update(1, 0, n-1, a-1, b);
        }
        else {
            cout << query(1, 0, n-1, a-1, b-1) el;
        }
    }
}