// File: main.cpp
// Author: Samuel Ren
// Created: 2025-11-14 16:48:20 EST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    int a[n];
    int m,b,c; cin >> a[0] >> m >> b >> c;
    for (int i=1; i<n; ++i) a[i]=((ll)a[i-1]*m+b)%c;
    int h=n/k;
    int po[h][2][k+1];
    auto ptr=a+0;
    for (int i=0; i<h; ++i) {
        po[i][0][0]=0;
        ptr=a+i*k-1;
        for (int j=0; j<k; ++j) po[i][0][j+1]=po[i][0][j]|(*(++ptr));
        po[i][1][k]=0;
        ptr=a+(i+1)*k;
        for (int j=k-1; ~j; --j) po[i][1][j]=po[i][1][j+1]|(*(--ptr));
    }
    int e=po[h-1][0][k];
    for (int i=0; i<h-1; ++i) for (int j=0; j<k; ++j) e^=po[i][1][j]|po[i+1][0][j];
    int f=0;
    for (int i=1; i<=n-h*k; ++i) e^=po[h-1][1][i]|(f|=a[h*k+i-1]);
    cout << e;
}
