// File: main.cpp
// Author: Samuel Ren
// Created: 2026-02-03 22:36:13 EST

#include <bits/stdc++.h>
using namespace std;

struct edge{
    int f, c, cap;
};

const int mn=405, inf=1'000'000'000;
int n;

int pot[mn];
edge e[mn][mn];

int mcmf(int fn) {
    int d[n];
    int prev[n];
    pair<int,int> tp;
    int cn;
    int pt;
    int tc=0;
    for (int it=0; it<fn; ++it) {
        d[0]=0;
        for (int i=1; i<n; ++i) d[i]=inf;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>  pq;
        pq.push({0, 0});
        while (pq.size()) {
            tp = pq.top();
            pq.pop();
            if (tp.first != d[tp.second]) continue;
            cn=tp.second;
            for (int i=0; i<n; ++i) if (e[cn][i].f < e[cn][i].cap && d[cn]+e[cn][i].c+pot[cn] < d[i]+pot[i]) {
                d[i]=d[cn]+e[cn][i].c+pot[cn]-pot[i];
                pq.push({d[i], i});
                prev[i]=cn;
            }
        }
        for (int i=0; i<n; ++i) pot[i] += d[i];
        tc += pot[n-1];
        pt=n-1;
        while (pt) {
            ++e[prev[pt]][pt].f;
            --e[pt][prev[pt]].f;
            pt=prev[pt];
        }
    }
    return tc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nv; cin >> nv;
    n = nv*2+2;
    int c;
    for (int i=1; i<=nv; ++i) {
        for (int j=1; j<=nv; ++j) {
            cin >> c;
            e[i][j+nv].c=c;
            e[i][j+nv].cap=1;
            e[j+nv][i].c=-c;
        }
    }
    for (int i=1; i<=nv; ++i) {
        e[0][i].cap=1;
        e[nv+i][2*nv+1].cap=1;
    }
    cout << mcmf(nv) << '\n';
    for (int i=1; i<=nv; ++i) for (int j=1; j<=nv; ++j) if (e[i][j+nv].f) {
        cout << i << ' ' << j << '\n';
        break;
    }
}
