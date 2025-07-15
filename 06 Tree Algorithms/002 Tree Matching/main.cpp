#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
#define pss pair<short, short>
#define MAX *max_element
#define MIN *min_element
#define rsz resize
 
vector<int> adj[200000];
pii dp[200000];
 
void dfs(int cn, int pn) {
    int md=-200000;
    bool cf = false;
    for (int i : adj[cn]) {
        if (i==pn) continue;
        cf = true;
        dfs(i, cn);
        dp[cn].se += max(dp[i].fi, dp[i].se);
        md = max(md, dp[i].se - dp[i].fi);
    }
    if(cf) dp[cn].fi = dp[cn].se+md+1;
    // dp[cn].fi = max(dp[cn].fi, dp[cn].se);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    forn(i,n-1) {
        int t1, t2; cin >> t1 >> t2;
        t1--;
        t2--;
        adj[t1].pb(t2);
        adj[t2].pb(t1);
    } 
    forn(i,n) {
        dp[i] = {0,0};
    }
    dfs(0, -1);
    cout << max(dp[0].fi, dp[0].se);
    // nl;
    // forn(i,n) cout << dp[i].fi spc << dp[i].se el;
}