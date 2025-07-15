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

const string ntl = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<char,int> ltn;

int main() {
    forn(i,26) ltn[ntl[i]]=i;
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s; cin >> s;
    int n=int(s.size());
    int chars[26]={0};
    forn(i,n) {
        chars[ltn[s[i]]]++;
    }
    int d1=0;
    forn(i,26) d1+=(chars[i]%2);
    if (d1>1) cout << "NO SOLUTION";
    else {
        forn(i,26) {
            forn(j,chars[i]/2) cout << ntl[i];
        }
        if (d1) {
            forn(i,26) if (chars[i]%2) cout << ntl[i];
        }
        for (int i=25; i>=0; i--) {
            forn(j,chars[i]/2) cout << ntl[i];
        }
    }
}