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
    int n,x; cin >> n >> x;
    int p[n];
    cina(p,n);
    sort(p,p+n);
    int p0=0, p1=n-1, tot=0;;
    while (p0<p1) {
        if (p[p0]+p[p1]<=x) {
            p0++;
            p1--;
            tot++;
        }
        else p1--;
    }
    cout << n-tot;
}