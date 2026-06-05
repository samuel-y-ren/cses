// File: main.cpp
// Author: Samuel Ren
// Created: 2026-02-04 09:45:44 EST

#include <bits/stdc++.h>
using namespace std;

struct edge{
    int dt, f, c, cap;
};

const int mn=505, inf=1'000'000'000;
int n;

int pot[mn];
vector<pair<edge,edge>> e;
vector<pair<edge*, edge*>> er[mn];

int mcmf(int fn) {
    int d[n];
    pair<edge*, edge*> prev[n];
    pair<int,int> tp;
    int cn;
    int pt;
    int tc=0;
    int dt;
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
            for (auto& i : er[cn]) if (i.first->f < i.first->cap && d[cn]+i.first->c+pot[cn] < d[i.first->dt]+pot[i.first->dt]) {
                dt=i.first->dt;
                d[dt]=d[cn]+i.first->c+pot[cn]-pot[dt];
                pq.push({d[dt], dt});
                prev[dt]=i;
            }
        }
        for (int i=0; i<n; ++i) pot[i] += d[i];
        if (pot[n-1]>inf) return -1;
        tc += pot[n-1];
        pt=n-1;
        while (pt) {
            ++prev[pt].first->f;
            --prev[pt].second->f;
            pt=prev[pt].second->dt;
        }
    }
    return tc;
}

vector<int> path;
void dfs(int cn) {
    path.emplace_back(cn);
    for (auto& i : er[cn]) if (i.first->f>0) {
        dfs(i.first->dt);
        i.first->f=0;
        i.second->f=0;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,k; cin >> n >> m >> k;
    int a,b;
    e.resize(m);
    for (int i=0; i<m; ++i) {
        cin >> a >> b;
        --a; --b;
        e[i].first.dt=b;
        e[i].first.c=1;
        e[i].first.cap=1;
        er[a].emplace_back(&e[i].first, &e[i].second);

        e[i].second.dt=a;
        e[i].second.c=-1;
        er[b].emplace_back(&e[i].second, &e[i].first);
    }
    int r=mcmf(k);
    cout << r << '\n';
    if (r!=-1) {
        while (k--){
            dfs(0);
            cout << path.size() << '\n';
            for (int i : path) cout << i+1 << ' ';
            cout << '\n';
            path.clear();
        }
    }
}
