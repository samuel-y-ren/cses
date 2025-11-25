cd // File: main.cpp
// Author: Samuel Ren
// Created: 2025-11-15 11:46:15 EST

#include <bits/stdc++.h>
using namespace std;

const int mn=405, me=10005;
struct edge{
    int a,b,r,c;
    edge(int a_, int b_, int r_, int c_) : a(a_), b(b_), r(r_), c(c_) {}
};
vector<edge> e;
int d[mn];
vector<edge>::iterator p[mn];
int tc=0;

bool sp(int n) {
    d[1]=0;
    for (int i=2; i<=n; ++i) d[i]=1000000000;
    for (int i=0; i<n; ++i) for (auto j=e.begin(); j!=e.end(); ++j) {
        if (d[j->b] > d[j->a]+j->c && j->r) {
            d[j->b]=d[j->a]+j->c;
            p[j->b]=j;
        }
    }
    if (d[n] < 1000000000) {
        int cn=n;
        tc+=d[n];
        while (cn!=1) {
            --(p[cn]->r);
            ++e[(p[cn]-e.begin())^1].r;
            cn=(p[cn]->a);
        }
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

}
