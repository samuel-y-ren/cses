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

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n; cin >> n;
    if (n%4==1 or n%4==2) ansno;
    else if (n%4==0) {
        ansyes;
        cout << n/2 el;
        forn(i,n/2) {
            if (i%2==0) cout << i+1 spc;
            else cout << n-i+1 spc;
        }
        cout el << n/2 el;
        forn(i,n/2) {
            if (i%2==0) cout << i+2 spc;
            else cout << n-i spc;
        }
    }
    else {
        n++;
        ansyes;
        vector<int> s1, s2;
        forn(i,n/2) {
            if (i%2==0) s1.pb(i+1);
            else s1.pb(n-i+1);
        }
        forn(i,n/2) {
            if (i%2==0) s2.pb(i+2);
            else s2.pb(n-i);
        }
        s1.erase(s1.begin()+1);
        s1.pb(n/2);
        s2.erase(s2.end()-2);
        cout << n/2 el;
        for (int i : s1) cout << i spc;
        cout el << n/2-1 el;
        for (int i : s2) cout << i spc;
    }
}