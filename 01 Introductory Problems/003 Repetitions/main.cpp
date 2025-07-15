#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define el << '\n'
#define ll long long
#define spc << ' '
#define forn(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353 
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s; cin >> s;
    int n=int(s.size());
    int cl=1;
    int mr=1;
    forn(i,1,n) {
        if (s[i] == s[i-1]) cl++;
        else cl=1;
        mr=max(mr,cl);
    }
    cout << mr;
}