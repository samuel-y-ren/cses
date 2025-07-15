#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define el << '\n'
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define forl(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353 
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"
#define cina(arr, n) for (int i=0; i<n; i++) cin >> arr[i]
#define fi first
#define se second
#define pii pair<int,int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    pii a[n];
    forn(i,n) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    // forn(i,n) cout << a[i].se spc;
    // forn(i,n) cout << a[i].fi spc << a[i].se el;
    // cout el;
    sort(a,a+n);
    // forn(i,n) cout << a[i].fi spc << a[i].se el;
    // int b[n];
    // forn(i,n) b[a[i].se] = i;
    int tot=1;
    forl(i,1,n) if (a[i].se<a[i-1].se) tot++;
    cout << tot;
}