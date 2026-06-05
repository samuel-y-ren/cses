#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")
#pragma GCC target("popcnt")
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
 
bitset<3000> b[3000];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int n; cin >> n;
    
    forn(i,n) {
        string temp; cin >> temp;
        bitset<3000> t(temp);
        swap(t, b[i]);
    }
    ll t=0;
    forn(i,n) {
        forl(j, i+1, n) {
            int temp = (b[i] & b[j]).count();
            t += temp * (temp-1) / 2;
        }
    }
    cout << t el;
}