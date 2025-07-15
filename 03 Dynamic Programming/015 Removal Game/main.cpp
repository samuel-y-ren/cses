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

// void set_max(ll& a, const ll& b) {
//     if (b>a) a=b;
// }

// void set_min(ll& a, const ll& b) {
//     if (b<a) a=b;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int x[n]; cina(x,n);
    ll dp[n][n];
    forn(i,n) forn(j,n) dp[i][j]=00;
    forn(i,n) {
        dp[i][i] = (n%2 ? 0 : -1) * x[i];
    }
    for (int i = n-2; i>=0; i--) {
        for (int j = i+1; j<n; j++) {
            // if (i==0 && j==n-1) cout << 'e';
            if ((n-j+i)%2) {
                // set_max(dp[i][j], dp[i+1][j]+dp[i]);
                // set_max(dp[i][j], dp[i+1][j]+dp[i]);
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
            else {
                dp[i][j] = min(dp[i+1][j]-x[i], dp[i][j-1]-x[j]);
            }
        }
    }
    ll s=0;
    forn(i,n) s+=x[i];
    // forn(i,n) {
    //     forn(j,n) cout << dp[i][j] spc;
    //     nl;
    // }
    cout << s+dp[0][n-1];
}