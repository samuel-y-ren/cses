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
    int n, m, k; cin >> n >> m >> k;
    int a[n];
    int b[n];
    cina(a,n);
    cina(b,m);
    sort(a,a+n);
    sort(b,b+m);
    int p0=0, p1=0, tot=0;
    while (p0<n and p1<m) {
        if (b[p1]-k <= a[p0] and a[p0] <= b[p1]+k) {
            p0++;
            p1++;
            tot++;
        }
        else if (a[p0] > b[p1]+k) {
            p1++;
        }
        else {
            p0++;
        }
    }
    cout << tot;
}