#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")
#define el << '\n'
#define nl cout << '\n'
#define cina(a,n) for (int i=0; i<n; i++) cin >> a[i]
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define forl(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<long long, long long>
#define MAX *max_element
#define MIN *min_element

short n, m;
short p2[15];

vector<short> pbm;
short n2;

short cbm;
void pc(short d) {
    if (d==n) {
        pbm.pb(cbm);
        return;
    }
    pc(d+1);
    cbm += p2[d];
    pc(d+1);
    cbm -= p2[d];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    p2[0]=1;
    forn(i,14) p2[i+1]=p2[i]*2;
    cin >> n >> m;
    pc(0);
    n2 = pbm.size();
    vector<short> trans[n2];
    forn(i,n2) {
        forn(j,n2) {
            if ((pbm[i]&pbm[j])==0) {
                short nc = pbm[i]|pbm[j];
                bool w = true;
                short bs[n];
                forn(k,n) {
                    bs[k] = (nc%p2[k+1])/p2[k];
                }
                short s0=0;
                for (short i : bs) {
                    if (i) {
                        if (s0%2) {
                            w=false;
                            break;
                        }
                        s0=0;
                    }
                    else s0++;
                }
                if (s0%2) continue;
                if (w) trans[i].pb(j);
            }
        }
    }
    // for (short i : pbm) cout << i spc;
    // nl;
    // forn(i,n2) {
    //     for (short j : trans[i]) cout << j spc;
    //     nl;
    // }
    int dp[m+1][n2]={};
    dp[0][0]=1;
    forn(i,m) {
        forn(j,n2) {
            for (int k : trans[j]) {
                dp[i+1][k] += dp[i][j];
                dp[i+1][k] %= MOD;
            }
        }
    }
    // forn(i,m+1) {
    //     forn(j,n2) cout << dp[i][j] spc;
    //     nl;
    // }
    cout << dp[m][0];
}