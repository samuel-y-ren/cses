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
 
void set_min(pii& a, const pii& b) {
    if (b<a) a=b;
}
 
bool sortp(int i1, int i2) {
    return __builtin_popcount (i1)<__builtin_popcount (i2);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p2[30];
    p2[0]=1;
    forn(i,29) p2[i+1] = p2[i]*2;
    int n, x; cin >> n >> x;
    int w[20]; cina(w,n);
    pii bm[p2[n]];
    forn(i,p2[n]) {
        bm[i].fi=1000000000;
    }
    bm[0] = {1,0};
    int po[p2[n]];
    forn(i,p2[n]) po[i]=i;
    sort(po,po+p2[n],sortp);
    for (int i : po) {
        forn(j,n) {
            if ((p2[j]|i) != i) {
                if (bm[i].se + w[j] > x) {
                    pii temp={bm[i].fi+1, w[j]};
                    set_min(bm[i+p2[j]], temp);
                }
                else {
                    pii temp={bm[i].fi, w[j] + bm[i].se};
                    set_min(bm[i+p2[j]], temp);
                }
            }
        }
    }
    cout << bm[p2[n]-1].fi;
}