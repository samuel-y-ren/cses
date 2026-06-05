// File: 3139.cpp
// Author: Samuel Ren
// Created: 2026-02-20 09:33:08 EST
 
#include <bits/stdc++.h>
using namespace std;
 
int lb[500];
 
void ms(int* a, int n) {
    if (n==1) return;
    int ls=n/2, rs=(n+1)/2;
    ms(a, ls);
    ms(a+ls, rs);
    memcpy(lb, a, ls*4);
    int* rb=a+ls;
    int l=0, r=0, t=0;
    while (l<ls && r<rs) {
        cout << "? " << lb[l] << ' ' << rb[r] << endl;
        string s; cin >> s;
        if (s=="YES") a[t++]=lb[l++];
        else a[t++]=rb[r++];
    }
    while (l<ls) a[t++]=lb[l++];
    while (r<rs) a[t++]=rb[r++];
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int a[n]; 
    for (int i=0; i<n; ++i) a[i]=i+1;
    ms(a, n);
    int p[n];
    for (int i=0; i<n; ++i) p[a[i]-1]=i+1;
    cout << "! ";
    for (int i : p) cout << i << ' ';
    cout << endl;
}