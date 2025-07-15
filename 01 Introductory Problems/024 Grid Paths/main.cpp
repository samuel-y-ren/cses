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

int tot=0;
string path;
int vis[7][7];
bool p=true;

bool check(int x, int y) {
    if (x<0 or x>6 or y<0 or y>6 or vis[x][y]) return false;
    return true;
}

void explore(int d, int x, int y) {
    if (d==48) {
        if (x==6 and y==0) {
            tot++;
            // cout << x spc << y el; 
            // forn(i,7) {
            //     forn(j,7) cout << vis[i][j] spc;
            //     cout el;
            // }
            // cout el;
        }
        return;
    }
    if (x<0 or x>6 or y<0 or y>6 or vis[x][y] or (x==6 and y==0)) return;
    bool cs[4] = {check(x+1,y),check(x-1,y),check(x,y+1),check(x,y-1)};
    if ((cs[0] and cs[1] and not cs[2] and not cs[3]) or (cs[2] and cs[3] and not cs[0] and not cs[1])) {
        // if (p) {
        //     cout << x spc << y el; 
        //     forn(i,7) {
        //         forn(j,7) cout << vis[i][j] spc;
        //         cout el;
        //     }
        //     cout el;
        // }
        // vis[x][y]=0;
        return;
    }
    // tot++;
    // if (p and d==9){
        // cout << x spc << y el; 
        // forn(i,7) {
        //     forn(j,7) cout << vis[i][j] spc;
        //     cout el;
        // }
        // cout el;
    // }
    // if (d==40) p=false;
    vis[x][y]=d+1;
    if (path[d] == '?') {
        explore(d+1,x+1,y);
        explore(d+1,x-1,y);
        explore(d+1,x,y+1);
        explore(d+1,x,y-1);
    }
    else if (path[d]=='R') explore(d+1,x,y+1);
    else if (path[d]=='L') explore(d+1,x,y-1);
    else if (path[d]=='U') explore(d+1,x-1,y);
    else explore(d+1,x+1,y);
    vis[x][y]=0; 
    return;
    
}

int main() {
    forn(i,7) forn(j,7) vis[i][j]=false;
    cin >> path;
    explore(0,0,0);
    cout << tot;
    // forn(i,7) {
    //     forn(j,7) cout << vis[i][j] spc;
    //     cout el;
    // }
}