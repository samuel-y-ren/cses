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
#define cina(arr, n) for (int i=0; i<n; i++) cin >> arr[i]
#define fi first
#define se second
#define pii pair<int,int>

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n,m; cin >> n >> m;
    int l = 1;
    int ind[n+2] = {0}, a[n+1] = {0};
    ind[n+1] = n+1;
    forl(i,1,n+1) {
		int x; cin>>x;
		ind[x] = i;
		a[i] = x;
    }
    int tot = 1;
    forl(i,1,n+1) {
		if (l > ind[i]) 
		tot++;
		l = ind[i];
    }
    forn(q,m) {
		int x,y; cin >> x >> y;
		int r = a[x], s = a[y];
		swap(a[x], a[y]);
		if (ind[r-1] <= ind[r] and ind[r-1] > y) tot++;
		if (ind[r-1] > ind[r] and ind[r-1] <= y) tot--;
		if (ind[r] <= ind[r+1] and y > ind[r+1]) tot++;
		if (ind[r] > ind[r+1] and y <= ind[r+1]) tot--;		
		ind[r] = y;
		if (ind[s-1] <= ind[s] and ind[s-1] > x) tot++;
		if (ind[s-1] > ind[s] and ind[s-1] <= x) tot--;
		if (ind[s] <= ind[s+1] and x > ind[s+1]) tot++;
		if (ind[s] > ind[s+1] and x <= ind[s+1]) tot--;	
		ind[s] = x;
		cout << tot el;
    }
}