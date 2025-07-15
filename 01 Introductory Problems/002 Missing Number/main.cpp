#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define el << '\n'
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define MOD 1000000007
#define MOD2 998244353 
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n; cin >> n;
    int a[n];
    forn(i,n-1) cin >> a[i];
    sort(a,a+n-1);
    a[n-1]=0;
    forn(i,n) {
        if (a[i] != i+1) {
            cout << i+1;
            break;
        }
    }
}