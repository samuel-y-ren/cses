// File: 1655.cpp
// Author: Samuel Ren
// Created: 2026-05-28 12:51:02 EST

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> trie(2);

void ins(int x) {
    int c = 1;
    for (int i=29; i>=0; --i) {
        if ((x>>i) & 1) {
            if (!trie[c].second) {
                trie[c].second = (int)trie.size();
                trie.emplace_back(0,0);
            }
            c = trie[c].second;
        } else {
            if (!trie[c].first) {
                trie[c].first = (int)trie.size();
                trie.emplace_back(0,0);
            }
            c = trie[c].first;
        }
    }
}

int fm(int x) {
    int c = 1;
    int res = 0;
    for (int i=29; i>=0; --i) {
        if ((x>>i) & 1) {
            if (trie[c].first) {
                c = trie[c].first;
                res |= (1<<i);
            } else {
                c = trie[c].second;
            }
        } else {
            if (trie[c].second) {
                c = trie[c].second;
                res |= (1<<i);
            } else {
                c = trie[c].first;
            }
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int px = 0;
    int ms = 0;
    ins(px);
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        ms = max(ms, fm(px ^= x));
        ins(px);
    }
    cout << ms;
}
