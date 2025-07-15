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
 
void set_max(ll& a, const ll& b) {
    if (b>a) a=b;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int a[n], b[n], p[n];
    set<int> ud;
    forn(i,n) {
        cin >> a[i] >> b[i] >> p[i];
        ud.insert(a[i]);
        ud.insert(b[i]);
    }
    map<int, int> cc;
    auto ptr = ud.begin();
    int m = ud.size();
    forn(i,m) {
        cc[*ptr]=i;
        ptr++;
    }
    forn(i,n) {
        a[i] = cc[a[i]];
        b[i] = cc[b[i]];
    }
    // forn(i,n) cout << a[i] spc << b[i] spc << p[i] el;
    vector<pii> pd[m];
    forn(i,n) {
        pii temp;
        temp.fi = b[i];
        temp.se = p[i];
        pd[a[i]].pb(temp);
    }
    ll dp[m+1]={0};
    forn(i,m) {
        set_max(dp[i+1],dp[i]);
        for (pii j : pd[i]) {
            set_max(dp[j.fi+1], dp[i]+j.se);
        }
    }
    cout << dp[m];
}