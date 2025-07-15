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
    int t; cin >> t;
    forn(q,t) {
        ll ta,tb; cin >> ta >> tb;
        ll a=min(ta,tb), b=max(ta,tb);
        if ((a+b)%3==0 and 2*a>=b) ansyes;
        else ansno;
        
    }
}