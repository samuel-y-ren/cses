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

int main() {
    int n; cin >> n;
    int a[n]; 
    forn(i,n) cin >> a[i];
    sort(a,a+n);
    int tot=1;
    forn(i,n-1) if (a[i+1] != a[i]) tot++;
    cout << tot;
}