// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-12 22:42:35 PST
 
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string g[n];
    for (int i=0; i<n; i++) cin >> g[i];
    bool p[n][n];
    bool u[n][n]={};
    vector<int> po[2*n-1][26];
    po[2*n-2][0].push_back(n-1);
    for (int s=2*n-2; s; s--) {
        for (int i=0; i<26; i++) {
            for (int j : po[s][i]) {
                int k = s-j;
                if (j && !u[j-1][k]) {
                    u[j-1][k]=true;
                    p[j-1][k]=true;
                    po[s-1][int(g[j-1][k])-65].push_back(j-1);
                }
                if (k && !u[j][k-1]) {
                    u[j][k-1]=true;
                    p[j][k-1]=false;
                    po[s-1][int(g[j][k-1])-65].push_back(j);
                }
            }
        }
    }
    int cx=0,cy=0;
    for (int i=0; i<2*n-1; i++) {
        cout << g[cx][cy];
        if (p[cx][cy]) cx++;
        else cy++;
    }
}
