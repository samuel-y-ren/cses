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
    int t; cin >> t;
    forn(q,t) {
        ll k; cin >> k;
        k--;
        forn(i,18) {
            k-=9*((ll) pow(10,i-1))*i;
            if (k<0) {
                k+=9*((ll) pow(10,i-1))*i;
                ll num=k/i+(ll) pow(10,i-1);
                int dig = i-k%i;
                ll dig10 = (ll) pow(10,dig);
                cout << (num%dig10)/(dig10/10) el;//spc << num spc << dig el;
                break;
            }
        }
    }
}