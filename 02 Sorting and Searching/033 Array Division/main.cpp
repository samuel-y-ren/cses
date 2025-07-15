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
#define pss pair<short, short>
#define MAX *max_element
#define MIN *min_element
#define rsz resize
 
int n, k, x[200000];
 
ll bs(ll l, ll u) {
    // cout << l spc << u el;
    if (l==u) return l;
    ll m = (l + u)/2;
    int c=1;
    ll p=0;
    forn(i,n) {
        if (p + x[i] > m) {
            c++;
            p=0;
        }
        p+=x[i];
        // if (m==7) cout << p el;
    }
    // if (p>m) c++;
    // if (m==7) cout << c el;
    if (c<=k) return bs(l, m);
    return bs(m+1, u);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cina(x, n);
    ll s = 0;
    forn(i,n) s += x[i];
    cout << bs(MAX(x, x+n), s);
}