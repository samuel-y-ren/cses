// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-15 10:21:15 PST
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<int> r[n+1];
    int oc[n+1]={};
    while (m--) {
        int a,b; cin >> a >> b;
        r[b].emplace_back(a);
        ++oc[a];
    }
    bitset<50000> dp[n+1]={};
    queue<int> q;
    for (int i=1; i<=n; ++i) if (!oc[i]) q.push(i);
    while (q.size()) {
        int cn=q.front();
        q.pop();
        dp[cn][cn]=1;
        for (auto i : r[cn]) {
            dp[i]|=dp[cn];
            if (!(--oc[i])) q.push(i);
        }
    }
    for (int i=1; i<=n; ++i) cout << dp[i].count() << ' ';
}