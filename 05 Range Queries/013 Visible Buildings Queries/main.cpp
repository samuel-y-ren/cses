// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-17 19:35:49 PST

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    int h[n]; for (int i=0; i<n; i++) cin >> h[i];
    pair<pair<int,int>,int> oq[q];
    for (int i=0; i<q; i++) {
        cin >> oq[i].first.first >> oq[i].first.second;
        oq[i].first.first--;
        oq[i].second=i;
    }
    sort(oq,oq+q);
    vector<int> ht={2000000000};
    vector<int> ps={-n  };
    int qp=q-1;
    int ans[q];
    for (int i=n-1; i>=0; i--) {
        while (h[i]>=ht.back()) {
            ht.pop_back(); ps.pop_back();
        }
        ht.push_back(h[i]); ps.push_back(-i);
        while (qp>-1 && oq[qp].first.first==i) {
            ans[oq[qp].second]=ps.end()-upper_bound(ps.begin(),ps.end(),-oq[qp].first.second);
            qp--;
        }
    }
    for (int i=0; i<q; i++) cout << ans[i] << '\n';
}
