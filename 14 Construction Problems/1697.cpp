// File: 1697.cpp
// Author: Samuel Ren
// Created: 2026-06-07 09:56:03 EST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    priority_queue<pair<int,int>> pq;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        if (x) pq.push({x, i+1});
    }
    vector<pair<int,int>> v;
    vector<pair<int,int>> r;
    while (pq.size()) {
        pair<int,int> c = pq.top();
        pq.pop();
        if (c.first > (int) pq.size()) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for (int i=0; i<c.first; ++i) {
            r.push_back(pq.top());
            v.emplace_back(pq.top().second, c.second);
            pq.pop();
        }
        for (int i=0; i<c.first; ++i) {
            if (r[i].first > 1) pq.push({r[i].first-1, r[i].second});
        }
        r.clear();
    }
    cout << v.size() << '\n';
    for (auto& i : v) {
        cout << i.first << ' ' << i.second << '\n';
    }
}
