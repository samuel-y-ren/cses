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
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n; cin >> n;
    int ec[5]={0,6,28,96,252};
    for (ll i=1; i<n+1; i++) {
        if (i<6) {
            cout << ec[i-1] el;
            continue;
        }
        ll tot=(i*i)*(i*i-1);
        tot-=8;
        tot-=24;
        tot-=16;
        tot-=(i-4)*4*4;
        tot-=(i-4)*4*6;
        tot-=(i-4)*(i-4)*8;
        cout << tot/2 el;
    }
}