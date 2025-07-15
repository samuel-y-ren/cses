#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define el << '\n'
#define nl cout << '\n'
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define forl(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353 
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"
 
int st[400000]={0};
int n;
 
void build(int ind) {
    if (ind>n-2) return;
    build(2*ind+1);
    build(2*ind+2);
    st[ind] = min(st[2*ind+1],st[2*ind+2]);
    return;
}
 
int range(int s, int e) {
    s+=n-1;
    e+=n-1;
    int ans=min(st[s],st[e]);
    while (s < e) {
        // if {
        //  (s==e) ans = min(ans,st[s]);
        //  break;
        // }
        if (!(s%2)) {
            ans = min(ans,st[s]);
            s++;
        }
        if ((e%2)) {
            ans = min(ans,st[e]);
            e--;
        }
        if (s+1==e) {
            ans = min(ans,min(st[s],st[e]));
            break;
        }
        // cout << s spc << e spc << ans el;
        if (s >= e) break;
        s = (s-1)/2;
        e = (e-1)/2;
    }
    return ans;
}
 
int main() {
    int q; cin >> n >> q;
    forl(i,n-1,2*n-1) {
        cin >> st[i];
    }
    build(0);
    // forn(i,2*n) cout << st[i] spc;
    // nl;
    forn(t,q) {
        int a,b; cin >> a >> b;
        cout << range(a-1,b-1) el;
    }
 
 
}