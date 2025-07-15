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
    int a[n];
    cina(a,n);
    ll ps[n+1];
    ps[0]=0;
    forn(i,n) ps[i+1] = ps[i]+a[i];
    ll ms=-1000000000000000000;
    ll rm=0;
    forl(i,1,n+1) {
        ms = max(ms,ps[i]-rm);
        rm = min(rm,ps[i]);
    }
    cout << ms;
}