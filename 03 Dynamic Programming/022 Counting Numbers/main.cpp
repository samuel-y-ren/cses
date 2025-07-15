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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll p10[19];
    p10[0]=1;
    forn(i,18) p10[i+1] = p10[i]*10;
    ll a, b; cin >> a >> b;
    if (a==1000000000000000000) a--;
    if (b==1000000000000000000) b--;
    short diga[18], digb[18];
    forn(i,18) {
        diga[17-i] = (a%p10[i+1])/p10[i];
        digb[17-i] = (b%p10[i+1])/p10[i];
    }
    ll dp[18][2][2][10]={};
    forl(i,diga[0]+1, digb[0]) dp[0][1][0][i]=1;
    if (diga[0]==digb[0]) dp[0][0][1][diga[0]]=1;
    else {
        dp[0][0][0][diga[0]]=1;
        dp[0][1][1][digb[0]]=1;
    }
    short l0a=0, l0b=0;
    forn(i,18) {
        if (diga[i]) break;
        else l0a++;
    } 
    forn(i,18) {
        if (digb[i]) break;
        else l0b++;
    } 
    forn(i,l0b) dp[i][0][1][0]=1;
    forl(i,l0b,l0a) dp[i][0][0][0]=1;
    // cout << l0b spc << l0a el;
    forn(i,17) {
        forn(j,10) {
            forn(k,10) {
                if (j==k) {
                    // if (j==0) {
                    //     if (i<l0a && i<l0b) {
                    //         dp[i][0][1][0]=1;
                    //     }
                    //     if (i<l0a) {
                    //         dp[i][0][0][0]=1;
                    //     }
                    // }
                    continue;
                }

                if (k==diga[i+1]) dp[i+1][0][0][k] += dp[i][0][0][j];
                if (k==digb[i+1]) dp[i+1][1][1][k] += dp[i][1][1][j];

                if (k==diga[i+1] && k==digb[i+1]) dp[i+1][0][1][k] += dp[i][0][1][j];
                if (k>diga[i+1] && k==digb[i+1]) dp[i+1][1][1][k] += dp[i][0][1][j];
                if (k==diga[i+1] && k<digb[i+1]) dp[i+1][0][0][k] += dp[i][0][1][j];
                if (k>diga[i+1] && k<digb[i+1]) dp[i+1][1][0][k] += dp[i][0][1][j];
 
                if (k>diga[i+1] && (k < digb[i+1] || i>=l0b)) dp[i+1][1][0][k] += dp[i][0][0][j];
                if (k<digb[i+1]) dp[i+1][1][0][k] += dp[i][1][1][j];

                dp[i+1][1][0][k] += dp[i][1][0][j];
            }
        }
    }
    // forn(i,17) cout << dp[i][1][0][2] spc;   
    ll s=0;
    forn(i,2) forn(j,2) forn(k,10) {
        s += dp[17][i][j][k];
        // if (dp[17][i][j][k]) cout << i spc << j spc << k el;
    }
    // forn(i,18) forn(j,2) forn(k,2) forn(l,10) {
    //     if (dp[i][j][k][l]) cout << i spc << j spc << k spc << l spc << dp[i][j][k][l] el;
    // } 
    // cout << dp[17][1][0][1];
    cout << s;
}