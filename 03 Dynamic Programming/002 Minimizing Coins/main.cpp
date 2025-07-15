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
    int n,x; cin >> n >> x;
	int c[n];
	cina(c,n);
	bool v[x+1] = {0};
	queue<pii> bfs;
	pii temp;
	temp.fi = 0;
	temp.se = 0;
	bfs.push(temp);
	v[0] = true;
	while (true) {
		if (bfs.size()==0) {
			cout << -1;
			break;
		}
		temp = bfs.front();
		// cout << temp.fi << endl;
		if (temp.fi == x) {
			cout << temp.se;
			break;
		}
		bfs.pop();
		for (int i : c) {
			if (i+temp.fi <= x and !v[temp.fi+i]) {
				pii t2;
				t2.fi = temp.fi+i;
				t2.se = temp.se+1;
				v[temp.fi+i] = true;
				bfs.push(t2);
			}
		}
	}
}
