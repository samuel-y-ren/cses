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

const string letters="abcdefghijklmnopqrstuvwxyz";
map<char,int>ltn;
void make_strings(vector<int> letter_reqs, int final_length, int depth, string built_string) {
    if (depth==final_length) {
        cout << built_string el;
        return;
    }
    for (int i=0; i<26; i++) {
        if (letter_reqs[i]>0) {
            letter_reqs[i]--;
            built_string.push_back(letters[i]);
            make_strings(letter_reqs, final_length, depth+1, built_string);
            letter_reqs[i]++;
            built_string.pop_back();
        }
    }
    return;
}

int fact(int n) {
    if (n<2) return 1;
    return fact(n-1)*n;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    forn(i,26) ltn[letters[i]]=i;
    string s; cin >> s;
    vector<int> letter_reqs;
    forn(i,26) letter_reqs.pb(0);
    for (char c : s) letter_reqs[ltn[c]]++;
    int nu=0,de=1;
    for (int i : letter_reqs) {
        nu+=i;
        de*=fact(i);
    }
    cout << fact(nu)/de el;
    make_strings(letter_reqs,nu,0,"");
}