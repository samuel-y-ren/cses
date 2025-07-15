#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int n, x; cin >> n >> x;
    int a[n]; cina(a,n);
    ll ps[n+1];
    ps[0] = 0;
    map<ll, int> sti;
    sti[0] = 0;
    forn(i,n) {
        ps[i+1] = ps[i] + a[i];
        sti[ps[i+1]] = 0;
    }
    ll tot=0;
    forn(i,n+1) {
        if (sti.find(ps[i]-x) != sti.end()) tot += sti[ps[i]-x];
        sti[ps[i]]++;
    }
    cout << tot;
}