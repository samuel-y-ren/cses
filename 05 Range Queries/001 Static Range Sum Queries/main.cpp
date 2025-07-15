#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define el << '\n'
#define nl cout << '\n'
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define forl(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353 
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"
 
int main() {
    int n, q; cin >> n >> q;
    ll ps[n+1];
    ps[0]=0;
    forn(i,n) {
        cin >> ps[i+1];
        ps[i+1] += ps[i];
    }
    // forn(i,n+1) cout << ps[i] spc;
    // nl;
    forn(t,q) {
        int a,b; cin >> a >> b;
        cout << ps[b]-ps[a-1] el;
    }
 
}