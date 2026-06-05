// File: 3112.cpp
// Author: Samuel Ren
// Created: 2026-02-20 09:28:27 EST
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int g=0;
    for (int i=29; ~i; --i) {
        cout << "? " << (g|(1<<i)) << endl;
        string s; cin >> s;
        if (s=="YES") g|=(1<<i);
    }
    cout << "! " << g+1 << endl;
}