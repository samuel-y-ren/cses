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

int o[4][4]={{-1,-1,-1,-1},{-1,-1,3,2},{-1,3,-1,1},{-1,2,1,-1}};

void solve(int s, int b, int e) {
    if (s==1) {
        cout << b spc << e el;
        return;
    }
    int tt=o[b][e];
    solve(s-1,b,tt);
    solve(1,b,e);
    solve(s-1,tt,e);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n; cin >> n;
    cout << (int) pow(2,n)-1 el;
    solve(n,1,3);
}