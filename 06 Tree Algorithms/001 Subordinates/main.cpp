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
 
int treep[200000];
vector<int> sub[200000];
 
void dfs(int cn) {
    for (int i : sub[cn]) {
        dfs(i);
        treep[cn] += treep[i];
    }
    treep[cn] += sub[cn].size();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    forn(i,n-1) {
        int temp; cin >> temp;
        sub[temp-1].pb(i+1);
    }
    dfs(0);
    forn(i,n) cout << treep[i] spc;
}