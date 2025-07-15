// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-08 20:45:35 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll x1,y1,x2,y2,x3,y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll x4=y2-y1,y4=x1-x2;
        ll x5=x3-x2,y5=y3-y2;
        ll dp=x4*x5+y4*y5;
        if (!dp) cout << "TOUCH\n";
        else if (dp<0) cout << "LEFT\n";
        else cout << "RIGHT\n";
    }
}
