#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")
#define el << '\n'
#define nl cout << '\n'
#define cina(a,n) for (int i=0; i<n; i++) cin >> a[i]
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define forl(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<long long, long long>
#define MAX *max_element
#define MIN *min_element

void set_min(int& a, const int& b) {
	if (b<a) a=b;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int dp[501][501];
	forl(i,1,501) forl(j,1,501) dp[i][j] = 1000000000;
	forn(i,501) {
		dp[i][i]=0;
	}
	forl(i,1,501) {
		forl(j,1,501) {
			forn(k,(i+2)/2) {
				set_min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
			}
			forn(k,(j+2)/2) {
				set_min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
			}
		}
	}
	int a,b; cin >> a >> b;
	cout << dp[a][b];
}
