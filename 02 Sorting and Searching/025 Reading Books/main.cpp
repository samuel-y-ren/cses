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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int n; cin >> n;
    ll s=0;
    int maxn=0;
    int temp;
    forn(i,n) {
        cin >> temp;
        maxn = max(maxn, temp);
        s += temp;
    }
    cout << max(s, 2ll*maxn);
}