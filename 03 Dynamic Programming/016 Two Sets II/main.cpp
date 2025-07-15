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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int m = (n*(n+1))/2;
    if (m%2) {
        cout << 0;
        return 0;
    }
    m/=2;
    int dp[m+1]={};
    dp[0]=1;
    forn(i,n) {
        for (int j=m; j>i; j--) {
            dp[j]+=dp[j-i-1];
            dp[j] %= MOD;
        }
    }
    cout << ((ll) dp[m] * ((MOD+1)/2))%MOD;
}