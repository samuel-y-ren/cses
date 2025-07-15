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
 
 
void set_min(int& a, const int& b) {
    if (b<a) a=b;
}
 
int lg[400005];
int p2[31];
 
vector<int> adj[200005];
 
int t;
vector<int> ep;
int vt[200005];
int dep[200005];
void et(int cn, int pn, int d) {
    vt[cn] = t;
    dep[cn] = d;
    t++;
    ep.pb(d);
    for (int i : adj[cn]) {
        if (i == pn) continue;
        et(i, cn, d+1);
        t++;
        ep.pb(d);
    }
}
 
 
int n;
int m;
 
vector<int> sp[21];
void psp() {
    m = ep.size();
    sp[0].rsz(m);
    forn(i,m) sp[0][i] = ep[i];
    forl(i,1,20) {
        if (1>(m+1-p2[i])) break;
        sp[i].rsz(m+1-p2[i]);
        forn(j, m+1-p2[i]) {
            sp[i][j] = min(sp[i-1][j], sp[i-1][j+p2[i-1]]);
        }
    }
    return;
}
 
int gsp(int a, int b) {
    // cout << a spc << b << endl;
    if (a==b) return 0;
    int ans = dep[a] + dep[b];
    a = vt[a];
    b = vt[b];
    if (a>b) swap(a,b);
    int rs = lg[b-a+1];
    // cout << a spc << b << endl;
    // cout << a spc << b spc spc << dep[a] spc << dep[b] spc << lg[b-a+1] spc << min(sp[rs][a], sp[rs][b-p2[rs]]) el;
    return ans - 2*min(sp[rs][a], sp[rs][b-p2[rs]]);
}
 
int main() {
    p2[0]=1;
    forn(i,30) p2[i+1] = p2[i]*2;
    for (int i=20; i>0; i--) {
        for (int j = min(p2[i], 400000); j>=0; j--) {
            lg[j] = i-1;
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int n, q; cin >> n >> q;
    forn(i, n-1) {
        int t1, t2; cin >> t1 >> t2;
        t1--;
        t2--;
        adj[t1].pb(t2);
        adj[t2].pb(t1);
    }
    et(0, -1, 0);
    psp();
    forn(i,q) {
        int t1, t2; cin >> t1 >> t2;
        t1--;
        t2--;
        cout << gsp(t1, t2) << endl;
    }
}