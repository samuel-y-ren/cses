// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-09 19:36:08 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ion(pair<ll,ll> p1, pair<ll,ll> p2, ll x, ll y) {
    ll dx1=p2.first-p1.first, dy1=p2.second-p1.second, dx2=x-p1.first, dy2=y-p1.second;
    if (dx1*dy2!=dx2*dy1) return false;
    if (p1>p2) swap(p1,p2);
    pair<ll,ll> p3={x,y};
    return (p1<=p3&&p3<=p2);
}

bool its(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    ll dx1=x2-x1, dy1=y2-y1, dx2=x4-x3, dy2=y4-y3;
    ll px1=dy1, py1=-dx1, px2=dy2, py2=-dx2;

    if (dx1*dy2==dx2*dy1) return false;
    ll h1 = (x1-x3)*px1+(y1-y3)*py1;
    ll l1 = dx2*px1+dy2*py1;
    bool b1= (l1>0 ? 0<=h1&&h1<=l1 : 0>=h1&&h1>=l1);
    ll h2 = (x3-x1)*px2+(y3-y1)*py2;
    ll l2 = dx1*px2+dy1*py2;
    bool b2= (l2>0 ? 0<h2&&h2<l2 : 0>h2&&h2>l2);
    b2|=(x2>y2 && ion(make_pair(x3,y3), make_pair(x4,y4), x1, y1));
    b2|=(x1>y1 && ion(make_pair(x3,y3), make_pair(x4,y4), x2, y2));

    return (b1&&b2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    pair<int,int> p[n]; for (int i=0; i<n; ++i) cin >> p[i].first >> p[i].second;
    while (q--) {
        int x,y; cin >> x >> y;
        bool t=ion(p[n-1],p[0],x,y);
        for (int i=1; i<n; ++i) if (t|=ion(p[i-1],p[i],x,y)) break;
        if (t) {
            cout << "BOUNDARY\n";
            continue;
        }
        t=its(p[n-1].first,p[n-1].second,p[0].first,p[0].second,x,y,1000000001,1000000001);
        for (int i=1; i<n; ++i) t^=its(p[i-1].first,p[i-1].second,p[i].first,p[i].second,x,y,1000000001,1000000001);
        cout << (t ? "INSIDE\n" : "OUTSIDE\n");
    }
}
