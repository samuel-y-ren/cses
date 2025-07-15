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
#define MAX *max_element
#define MIN *min_element
#define rsz resize
 
vector<ll> adj[200001];
 
ll dp[200001];
ll s[200001];
ll ma[200001];
 
void dfs(ll cn, ll pn) {
    for (ll i : adj[cn]) {
        if (i == pn) continue;
        dfs(i, cn);
        s[cn] += s[i];
        dp[cn] += dp[i];
    }
    dp[cn] += s[cn];
    s[cn]++;
    // cout << dp[cn] el;
}
 
void reroot(ll n1, ll n2) {
    dp[n1] -= dp[n2];
    s[n1] -= s[n2];
    dp[n1] -= s[n2];
    dp[n2] += dp[n1];
    s[n2] += s[n1];
    dp[n2] += s[n1];
}
 
void dfs2(ll cn, ll pn) {
    ma[cn] = dp[cn];
    for (ll i : adj[cn]) {
        if (i != pn) {
            reroot(cn, i);
            dfs2(i, cn);
        }
    }
    reroot(cn, pn);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    ll n; cin >> n;
    forn(i,n-1) {
        ll t1, t2; cin >> t1 >> t2;
        t1--;
        t2--;
        adj[t1].pb(t2);
        adj[t2].pb(t1);
    }
    // forl(i, 2, n) {
    //     adj[1].pb(i);
    //     adj[i].pb(1);
    // }
    // adj[0].pb(1);
    // adj[1].pb(0);
    dfs(0, -1);
    dfs2(0, -1);
    forn(i,n) cout << ma[i] spc;
    // cout el << ma[199999] el;
}