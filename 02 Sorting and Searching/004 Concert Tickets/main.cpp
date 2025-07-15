#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define el << '\n'
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define forl(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353 
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"
#define cina(arr, n) for (int i=0; i<n; i++) cin >> arr[i]

int main() {
    int n,m; cin >> n >> m;
    multiset<int> h;
    forn(i,n) {
        int temp; cin >> temp;
        h.insert(temp);
    }
    forn(q,m) {
        int t; cin >> t;
        multiset<int>::iterator pos = h.upper_bound(t);
        if (pos == h.begin()) {
            cout << -1 el;
            continue;
        }
        else {
            pos--;
            cout << *pos el;
            h.erase(pos);
        }
    }
    // multiset<int>::iterator temp = h.upper_bound(0);
    // multiset<int>::iterator temp2 = h.begin();
    // cout << *temp spc << *temp2;
    
}