#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define el << '\n'
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define forl(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353 
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"

int bs[20]={0};
ll mindiff = 1000000000000000000;
int n;
int w[20];

void solve(int d) {
    if (n==d) {
        ll s0=0,s1=0;
        forn(i,n) {
            if (bs[i]) s1+=w[i];
            else s0+=w[i];
        }
        mindiff=min(mindiff,abs(s1-s0));
        return;
    }
    solve(d+1);
    bs[d]=1;
    solve(d+1);
    bs[d]=0;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n;
    forn(i,n) cin >> w[i];
    solve(0);
    cout << mindiff;
}