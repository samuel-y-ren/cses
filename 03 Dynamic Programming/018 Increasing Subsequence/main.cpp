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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int a[n]; cina(a,n);
    set<pii> ch;
    pii temp;
    temp.fi = 0;
    temp.se = 0;
    ch.insert(temp);
    forn(i,n) {
        pii ns;
        ns.fi = a[i];
        ns.se = 0;
        auto ptr = ch.lower_bound(ns);
        ptr--;
        ns.se = (*ptr).se+1;
        temp.fi = a[i];
        while (true) {
            ptr = ch.lower_bound(temp);
            if (ptr==ch.end()) break;
            if ((*ptr).se < ns.se) ch.erase(ptr);
            else break;
        }
        // cout << ns.fi spc << ns.se el;
        ch.insert(ns);
    }
    temp.fi = a[n-1];
    int maxans=0;
    auto ptr = ch.begin();
    while (ptr != ch.end()) {
        maxans = max(maxans, (*ptr).se);
        ptr++;
    }
    cout << maxans;
}