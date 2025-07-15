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

int main() {
    int n; cin >> n;
    int a[n], b[n];
    forn(i,n) cin >> a[i] >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    int mp=0;
    int p0=0, p1=0;
    while (p0<n) {
        if (a[p0]<b[p1]) {
            p0++;
            mp = max(mp,p0-p1);
        }
        else p1++;
    }
    cout << mp;
}