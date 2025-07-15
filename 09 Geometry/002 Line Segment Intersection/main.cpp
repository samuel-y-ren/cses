// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-09 17:15:40 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll x1,y1,x2,y2,x3,y3,x4,y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        ll dx1=x2-x1, dy1=y2-y1, dx2=x4-x3, dy2=y4-y3;
        ll px1=dy1, py1=-dx1, px2=dy2, py2=-dx2;

        if (dx1*dy2==dx2*dy1) {
            if (px1*(x3-x1)+py1*(y3-y1)) {
                cout << "NO\n";
                continue;
            }
            pair<ll,ll> l1={x1,y1},l2={x2,y2},l3={x3,y3},l4={x4,y4};
            if (l1>l2) swap(l1,l2);
            if (l3>l4) swap(l3,l4);
            cout << ((l1<=l3&&l3<=l2)||(l1<=l4&&l4<=l2)||(l3<=l1&&l1<=l4)||(l3<=l2&&l2<=l4) ? "YES\n" : "NO\n");
            continue;
        }
        ll h1 = (x1-x3)*px1+(y1-y3)*py1;
        ll l1 = dx2*px1+dy2*py1;
        bool b1= (l1>0 ? 0<=h1&&h1<=l1 : 0>=h1&&h1>=l1);
        ll h2 = (x3-x1)*px2+(y3-y1)*py2;
        ll l2 = dx1*px2+dy1*py2;
        bool b2= (l2>0 ? 0<=h2&&h2<=l2 : 0>=h2&&h2>=l2);
        cout << (b1&&b2 ? "YES\n" : "NO\n");
    }
}
