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
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int n; cin >> n;
    vector<pii> a, d;
    forn(i,n) {
        a.pb({0,i});
        d.pb({0,i});
        cin >> a.back().fi >> d.back().fi;
        a.back().fi--;
        d.back().fi--;
    }
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    a.pb({INT_MAX, -1});
    d.pb({INT_MAX, -1});
    int p1=0, p2=0;
    int rs[n];
    set<int> ra;
    int ru=1;
    forn(r, 2*n) {
        if (a[p1].fi <= d[p2].fi) {
            if (ra.size()) {
                rs[a[p1].se] = *ra.begin();
                ra.erase(ra.begin());
            }
            else {
                rs[a[p1].se] = ru;
                ru++;
            }
            p1++;
        }
        else {
            ra.insert(rs[d[p2].se]);
            p2++;
        }
    }
    cout << MAX(rs, rs+n) el;
    for (int i : rs) cout << i spc;
}