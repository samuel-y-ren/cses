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
    int n; cin >> n;
	int dp[n+1];
	forn(i,n) dp[i]=2000000;
	dp[n] = 0;
	for (int i=n; i>0; i--) {
		string ns = to_string(i);
		for (char j : ns) dp[i-int(j)+int('0')] = min(dp[i-int(j)+int('0')],dp[i]+1);
	}
	cout << dp[0];
}
