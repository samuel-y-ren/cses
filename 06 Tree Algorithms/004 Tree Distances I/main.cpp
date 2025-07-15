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
 
vector<int> adj[200000];
 
vector<int> st[200000];
int dp[200000];
int ma[200000];
 
void set_max(int& a, const int& b) {
    if (b>a) a=b;
}
 
void dfs(int cn, int pn) {
    // cout << cn spc << pn el;
    bool cf = false;
    for (int i : adj[cn]) {
        if (i == pn) continue;
        dfs(i, cn);
        cf = true;
        set_max(dp[cn], dp[i]);
        // cout << 'm' << cn spc << i el;
    }
    if (cf) dp[cn]++;
    // cout << cn spc << dp[cn] el;
}
 
void reroot(int n1, int n2) {
    if (n2==-1) return;
    if (dp[n2]+1 == st[n1].back()) {
        dp[n1] = st[n1][st[n1].size()-2];
    }
    set_max(dp[n2], dp[n1]+1);
}
 
void dfs2(int cn, int pn) {
    int m = (int) adj[cn].size();
    st[cn].rsz(m+1);
    st[cn][m] = 0;
    forn(i,m) {
        st[cn][i] = dp[adj[cn][i]]+1;
    }
    sort(st[cn].begin(), st[cn].end());
    ma[cn] = st[cn][m];
    // dp[cn] = st[m];
    for (int i : adj[cn]) {
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
    int n; cin >> n;
    forn(i,n-1) {
        int t1, t2; cin >> t1 >> t2;
        t1--;
        t2--;
        adj[t1].pb(t2);
        adj[t2].pb(t1);
    }
    dfs(0, -1);
    dfs2(0, -1);
    forn(i,n) cout << ma[i] spc;
}