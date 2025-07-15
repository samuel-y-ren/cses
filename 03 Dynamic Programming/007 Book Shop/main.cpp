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
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, x; cin >> n >> x;
	int h[n], s[n];
	cina(h,n);
	cina(s,n);
	int dp[x+1]={0};
	forn(i,n) for (int j=x-h[i]; j>=0; j--) dp[j+h[i]] = max(dp[j+h[i]], dp[j]+s[i]);
	// forn(i,x) cout << dp[i] spc;
	cout << dp[x];
}
