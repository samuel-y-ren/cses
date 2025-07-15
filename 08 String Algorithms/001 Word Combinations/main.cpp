// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-06 16:46:59 PST

#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;

struct t{
    bool e;
    t* c[26];
    t() {
        e=false;
        fill(c,c+26,nullptr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    int si[n]; for (int i=0; i<n; ++i) si[i]=int(s[i])-97;
    int k; cin >> k;
    t trie;
    while (k--) {
        string d; cin >> d;
        t* ptr= &trie;
        for (char c : d) {
            int nt=int(c)-97;
            if (!(*ptr).c[nt]) (*ptr).c[nt]=new t;
            ptr=(*ptr).c[nt];
        }
        (*ptr).e=true;
    }
    int dp[n+1]={};
    dp[0]=1;
    for (int i=0; i<n; ++i) {
        t* ptr = &trie;
        for (int j=i; j<n; ++j) {
            ptr=(*ptr).c[si[j]];
            if (!ptr) break;
            if ((*ptr).e) dp[j+1] = (dp[j+1]+dp[i])%MOD;
        }
    }
    cout << dp[n];
}