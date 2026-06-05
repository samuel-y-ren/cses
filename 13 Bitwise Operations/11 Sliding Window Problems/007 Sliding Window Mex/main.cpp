// File: main.cpp
// Author: Samuel Ren
// Created: 2026-02-08 13:25:23 EST

#include <bits/stdc++.h>
using namespace std;

void rem(set<pair<int,int>>& s, vector<pair<int,int>>& m, pair<int,int> r) {
    auto ptr=s.lower_bound(r);
    while (ptr != s.end() && ptr->first < r.second) {
        if (ptr->second <= r.second) m.push_back(*ptr);
        else {
            m.emplace_back(ptr->first, r.second);
            s.insert({r.second, ptr->second});
        }
        s.erase(ptr);
        ptr=s.lower_bound(r);
    }
    if (ptr != s.begin() && (--ptr)->second > r.first) {
        if (r.second>=ptr->second) {
            m.emplace_back(r.first, ptr->second);
            s.insert({ptr->first, r.first});
            s.erase(ptr);
        }
        else {
            m.push_back(r);
            s.insert({ptr->first, r.first});
            s.insert({r.second, ptr->second});
            s.erase(ptr);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> vi[k+1];
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        if (x<=k) vi[x].emplace_back(i);
    }
    set<pair<int,int>> prev={{0,n-k+1}};
    set<pair<int,int>> nxt;
    vector<pair<int,int>> v;
    int ans[n-k+1];
    for (int i=0; i<k+1; ++i) {
        v.emplace_back(-1,-1);
        for (int j : vi[i]) {
            if (max(0,j-k+1) <= v.back().second) v.back().second = min(n-k+1, j+1);
            else v.emplace_back(max(0,j-k+1), min(n-k+1, j+1));
        }
        v.emplace_back(n, n);
        vector<pair<int,int>> ia;
        int m = (int) v.size()-1;
        for (int j=0; j<m; ++j) rem(prev, ia, {v[j].second, v[j+1].first});
        v.clear();
        for (auto j : ia) for (int l=j.first; l<j.second; ++l) ans[l]=i;
    }
    for (int i : ans) cout << i << ' ';
    cout << endl;
}
