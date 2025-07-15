#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	vector<int> adj[n+1];
	for (int i=0; i<m; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ds[n+1]; for (int i=0; i<=n; i++) ds[i]=0;
	queue<pair<int,int>> q;
	q.push(make_pair(n,1));
	while (q.size()) {
		int x=q.front().first, d=q.front().second;
		q.pop();
		// cout << x << ' ' << d << '\n';
		if (ds[x]) continue;
		ds[x]=d;
		for (int i : adj[x]) q.push(make_pair(i,d+1));
	}
	if (ds[1]){
		int l=ds[1]-1;
		cout << l+1 << '\n';
		int cx=1;
		for (int i=0;i<=l;i++) {
			cout << cx << ' ';
			for (int j : adj[cx]) {
				if (ds[j]==l-i) {
					cx=j;
					break;
				}
			}
		}
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
	// for (int i=0; i<=n; i++) cout << ds[i] << ' ';
}