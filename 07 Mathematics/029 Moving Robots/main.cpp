// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-04 17:24:51 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<vector<vector<double>>> g(8,vector<vector<double>>(8,vector<double>(64,0))), ng(8,vector<vector<double>>(8,vector<double>(64,0)));
    for (int i=0; i<64; ++i) g[i/8][i%8][i]=1;
    while (n--) {
        for (int i=0; i<8; ++i) for (int j=0; j<8; ++j) for (int k=0; k<64; ++k) ng[i][j][k]=0;
        for (int k=0; k<64; ++k) {
            ng[0][1][k]+=g[0][0][k]*2;
            ng[1][0][k]+=g[0][0][k]*2;
            ng[6][7][k]+=g[7][7][k]*2;
            ng[7][6][k]+=g[7][7][k]*2;
            ng[0][6][k]+=g[0][7][k]*2;
            ng[1][7][k]+=g[0][7][k]*2;
            ng[6][0][k]+=g[7][0][k]*2;
            ng[7][1][k]+=g[7][0][k]*2;
        }
        for (int i=1; i<7; ++i) for (int k=0; k<64; ++k) {
            double v=g[i][0][k]*4/3;
            ng[i-1][0][k]+=v;
            ng[i+1][0][k]+=v;
            ng[i][1][k]+=v;
            v=g[i][7][k]*4/3;
            ng[i-1][7][k]+=v;
            ng[i+1][7][k]+=v;
            ng[i][6][k]+=v;
            v=g[0][i][k]*4/3;
            ng[0][i-1][k]+=v;
            ng[0][i+1][k]+=v;
            ng[1][i][k]+=v;
            v=g[7][i][k]*4/3;
            ng[7][i-1][k]+=v;
            ng[7][i+1][k]+=v;
            ng[6][i][k]+=v;
        }
        for (int i=1; i<7; ++i) for (int j=1; j<7; ++j) for (int k=0; k<64; ++k) {
            double v=g[i][j][k];
            ng[i-1][j][k]+=v;
            ng[i+1][j][k]+=v;
            ng[i][j+1][k]+=v;
            ng[i][j-1][k]+=v;
        }
        for (int i=0; i<8; ++i) for (int j=0; j<8; ++j) for (double &k : ng[i][j]) k/=4;
        swap(g,ng);
    }
    double s=0;
    for (int i=0; i<8; ++i) for (int j=0; j<8; ++j) {
        double c=1;
        for (int k=0; k<64; ++k) c*=1-g[i][j][k];
        s+=c;
    }
    cout << fixed << setprecision(6) << s;
}
