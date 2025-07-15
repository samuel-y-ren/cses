// File: main.cpp
// Author: Samuel Ren
// Created: 2025-05-27 21:12:04 PST

#include <bits/stdc++.h>
using namespace std;

const int mn=200005;

vector<int> adj[mn];
bool ud[mn];

int st[mn];

int l;
int fc(int u, int p) {
    st[u]=0;
    int r=0;
    for (int i : adj[u]) if (i!=p&&!ud[i]) {
        int x;
        if (x=fc(i,u)) r=x;
        st[u]+=st[i];
    }
    ++st[u];
    if (r) return r;
    if (st[u]>=l) return u;
    return 0;
}

int al,ar;
int kl,kr;
long long ans;

int dt[mn];
void fd(int u, int p, int d) {
    ++dt[d++];
    for (int i : adj[u]) if (i!=p&&!ud[i]) fd(i,u,d);
}

void cd(int u, int s) {
    ud[u]=true;
    int nn[s]; for (int i=1; i<s; ++i) nn[i]=0;
    nn[0]=1;
    long long cs=0;
    for (int i : adj[u]) if (!ud[i]) {
        l=0;
        fc(i,u);
        l=(st[i]+1)>>1;
        int nc=fc(i,u);
        fd(i,u,1);
        for (int j=1; j<=min(st[i],ar); ++j) {
            if (kl-->0&&kl<s) cs+=nn[kl];
            if (--kr<s) cs-=nn[kr];
            ans+=cs*dt[j];
        }
        while (kl<al) {
            if (kr++<s) cs+=nn[kr-1];
            if (++kl>0&&kl<=s) cs-=nn[kl-1];
        }
        for (int j=1; j<=st[i]; ++j) {
            nn[j]+=dt[j];
            if (kl<=j&&j<kr) cs+=dt[j];
            dt[j]=0;
        }
        cd(nc,st[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n >> al;
    ar=al+1;
    kl=al; kr=ar;
    for (int i=1; i<n; i++) {
        int a,b; cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    l=(n+1)/2;
    int ic=fc(1,0);
    l=n;
    fc(ic,0);
    cd(ic,n);
    cout << ans;

}
