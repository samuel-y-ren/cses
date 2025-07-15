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

char field[8][8];
int tot=0;

vector<int> queens;

void solve(int d) {
    // for (int i : queens) cout << i spc;
    // cout el;
    if (d==8) {
        tot++;
        return;
    }
    forn(i,8) {
        if (field[d][i]=='*') continue;
        bool w=true;
        forn(j,d) {
            if (abs(i-queens[j])==abs(d-j) or i==queens[j]) w=false;
        }
        if (!w) continue;
        queens.pb(i);
        solve(d+1);
        queens.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    forn(i,8) {
        string temp; cin >> temp;
        forn(j,8) {
            field[i][j]=temp[j];
        }
    }
    solve(0);
    cout << tot;
}