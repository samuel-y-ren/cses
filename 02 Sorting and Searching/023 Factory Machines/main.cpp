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
 
int n;
ll t; 
int k[200000];
 
ll bs(ll l, ll u) {
    // cout << l spc << u el;
    if (l==u) return l;
    // cout << l spc << u el;
    ll m = (l + u)/2;
    ll pm=0;
    forn(i,n) pm += m/k[i];
    if (pm >= t) return bs(l, m);
    return bs(m+1, u);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t;
    cina(k,n);
    cout << bs(0, 2000000000000000000/n);
}