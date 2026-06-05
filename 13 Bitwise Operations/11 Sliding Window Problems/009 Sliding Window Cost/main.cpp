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
#define pss pair<short, short>
#define MAX *max_element
#define MIN *min_element
#define rsz resize
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    int x[n]; cina(x, n);
    int x2[k];
    forn(i,k) x2[i] = x[i];
    sort(x2, x2+k);
    multiset<int> lh, uh;
    ll lc=0, uc=0;
    int ts = (k+1)/2;
    forn(i, ts) {
        lh.insert(x2[i]);
        lc += x2[i];
    }
    forl(i, ts, k) {
        uh.insert(x2[i]);
        uc += x2[i];
    }
    int m = *lh.rbegin();
    cout << (ll) m * lh.size() - lc + uc - (ll) m * uh.size() spc;
    // cout << 'l';
    // for (int i : lh) cout << i spc;
    // nl;
    // cout << 'u';
    // for (int i : uh) cout << i spc;
    // nl;
 
    forn(i, n-k) {
        m = *lh.rbegin();
        if (x[i] <= m) {
            lh.erase(lh.find(x[i]));
            lc -= x[i];
        }
        else {
            uh.erase(uh.find(x[i]));
            uc -= x[i];
        }
        if (uh.size() and !lh.size()) {
            swap(lh, uh);
            swap(lc, uc);
        }
        m = (lh.size() ? *lh.rbegin() : INT_MAX);
        if (x[i+k] <= m) {
            lh.insert(x[i+k]);
            lc += x[i+k];
        }
        else {
            uh.insert(x[i+k]);
            uc += x[i+k];
        }
        if (lh.size()>ts) {
            uh.insert(*lh.rbegin());
            uc += *lh.rbegin();
            lc -= *lh.rbegin();
            auto ptr = lh.end();
            ptr--;
            lh.erase(ptr);
        }
        else if (lh.size()<ts) {
            lc += *uh.begin();
            uc -= *uh.begin();
            lh.insert(*uh.begin());
            uh.erase(uh.begin());
        }
        m = *lh.rbegin();
        cout << (ll) m * lh.size() - lc + uc - (ll) m * uh.size() spc;
        // cout.flush();
    }
}