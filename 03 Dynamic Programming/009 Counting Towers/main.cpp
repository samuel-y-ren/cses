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
    ll pos[1000000][2]={0};
    pos[0][0]=1;
    pos[0][1]=1;
    forn(i,999999) {
        pos[i+1][0] = (4*pos[i][0] + pos[i][1]) % MOD;
        pos[i+1][1] = (pos[i][0] + 2*pos[i][1]) % MOD;
    }
    int t; cin >> t;
    forn(q,t) {
        int n; cin >> n;
        n--;
        cout << (pos[n][0] + pos[n][1]) % MOD el;
    }
}   