// File: main.cpp
// Author: Samuel Ren
// Created: 2025-11-24 18:07:32 EST

#include <bits/stdc++.h>
using namespace std;

const int mn=405;
int e[mn][mn][3];
vector<int> adj[405];
int pot[mn];

void sp(int n) {
    for (int st=0; st<n; ++st) for (int i=0; i<n; ++i) for (int j : adj[i]) pot[j]=min(pot[j], pot[i]+e[i][j][0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j) {
        adj[i].emplace_back(n+j);
        adj[n+j].emplace_back(i);
        cin >> e[i][n+j][0];
        e[i][n+j][2]=1;
        e[n+j][i]=-e[n+j][i];
    }
    for (int i=1; i<=n; ++i) {
        e[0][i][2]=e[n+i][2*n+1][2]=1;
        adj[0].emplace_back(i);
        adj[i].emplace_back(0);
        adj[n+i].emplace_back(2*n+1);
        adj[2*n+1].emplace_back(n+i);
    }
    // for (int i=0; i<2*n+2; ++i) {
    //     e[2*n+2][i]=0;
    // }

}
