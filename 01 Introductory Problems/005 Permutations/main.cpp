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
    int n; cin >> n;
    if (n==1) cout << 1;
    else if (n<4) cout << "NO SOLUTION";
    else {
        for (int i=2; i<=n; i+=2) cout << i spc;
        for (int i=1; i<=n; i+=2) cout << i spc;
    }
}