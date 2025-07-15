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
    int n; cin >> n;
    pii a[n];
    forn (i,n) cin >> a[i].fi >> a[i].se;
    sort(a,a+n,sortpii);
    multiset<int> b;
    forn(i,n) b.insert(a[i].se);
    int tot=0;
    int p=0;
    while (p<n) {
        tot++;
        int nt = *b.begin();
        while (a[p].fi<nt and p<n) {
            b.erase(b.find(a[p].se));
            p++;
        }
    }
    cout << tot;
}