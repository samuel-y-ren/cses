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
        ll x,y; cin >> y >> x;
        if (x==y) {
            cout << x*(x-1)+1 el;
        }
        else if (x<y){
            if (y%2) cout << (y-1)*(y-1)+x el;
            else cout << y*(y-1)+1+(y-x) el;
        }
        else {
            if (x%2) cout << x*(x-1)+1+(x-y) el;
            else cout << (x-1)*(x-1)+y el;
        }
    }
}