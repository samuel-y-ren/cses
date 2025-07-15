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

bool sortpii(pii p1, pii p2) {
    if (p1.fi != p2.fi) return p1.fi<p2.fi;
    return p1.se < p2.se;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x; cin >> n >> x;
    pii a[n];
    forn (i,n) {
        cin >> a[i].fi; a[i].se=i+1;
    }
    sort(a,a+n,sortpii);
    int p0=0;
    int p1=n-1;
    bool f=false;
    while (p0<p1) {
        if (a[p0].fi+a[p1].fi == x) {
            f=true;
            cout << a[p0].se spc << a[p1].se;
            break;
        }
        if (a[p0].fi+a[p1].fi < x) p0++;
        else p1--;
    }
    if (!f) cout << "IMPOSSIBLE";
}