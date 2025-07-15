// File: main.cpp
// Author: Samuel Ren
// Created: 2025-06-03 20:50:09 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf=2000000000000000000;

struct sm {
    vector<vector<ll>> m;
    int n;
    sm(vector<vector<ll>> m): m(m) {
        n = m.size();
    } 
    sm(int n): n(n) {
        m.resize(n);
        for (auto &i : m) i.resize(n,inf);
    }
    sm operator*(const sm& other) const {
        sm r(n);
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) for (int k=0; k<n; ++k) r.m[i][j]=min(r.m[i][j],m[i][k]+other.m[k][j]);
        return r;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k; cin >> n >> m >> k;
    sm b(n);
    for (int i=0; i<m; ++i) {
        int x, y, z; cin >> x >> y >> z;
        --x; --y;
        b.m[x][y]=min(b.m[x][y],(ll)z);
    }
    sm c=b;
    sm rt=b;
    --k;
    for (int i=0; i<30; ++i) {
        if (k&(1<<i)) rt=rt*c;
        c=c*c;
    }
    cout << (rt.m[0][n-1]==inf ? -1 : rt.m[0][n-1]);
}
