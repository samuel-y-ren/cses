// File: main.cpp
// Author: Samuel Ren
// Created: 2025-10-31 15:13:43 EST

#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
const double pi=3.1415926535897932384626338327950288d;
typedef long long ll;

void fft(vector<cd>& a, int n, bool inv) {
    if (n==1) return;
    const int half=(n>>1);
    vector<cd> even(half),odd(half);
    for (int i=0; i<half; ++i) {
        even[i]=a[i<<1];
        odd[i]=a[(i<<1)|1];
    }
    fft(even,half,inv);
    fft(odd,half,inv);
    double arg=pi/half;
    cd w(cos(pi/half),(inv ? -sin(pi/half) : sin(pi/half))), cw(1);
    if (inv) arg=-arg;
    for (int i=0; i<half; ++i) {
        a[i]=even[i]+cw*odd[i];
        a[i|half]=even[i]-cw*odd[i];
        cw*=w;
    }
}

vector<ll> conv(const vector<int>& a, const vector<int>& b) {
    vector<cd> ca(a.begin(),a.end()),cb(b.begin(),b.end());
    int n=1<<(32-__builtin_clz(a.size()+b.size()));
    ca.resize(n); cb.resize(n);
    fft(ca,n,0); fft(cb,n,0);
    for (int i=0; i<n; ++i) ca[i]*=cb[i];
    fft(ca,n,1);
    vector<ll> res(n);
    for (int i=0; i<n; ++i) res[i]=llroundl(ca[i].real()/n);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n,m; cin >> k >> n >> m;
    vector<int> a(k), b(k);
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        ++a[x-1];
    }
    for (int i=0; i<m; ++i) {
        int x; cin >> x;
        ++b[x-1];
    }
    vector<ll> c=conv(a,b);
    for (int i=0; i<2*k-1; ++i) cout << c[i] << ' ';
}
