#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,m; cin >> n >> m;
	vector<pair<int,int>> adj[2*n];
	for (int i=0; i<m; i++) {
		int a,b,c; cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({b,c});
		adj[a].push_back({b+n,c/2});
		adj[a+n].push_back({b+n,c});
	}
	ll d[2*n]; for (int i=0; i<2*n; i++) d[i]=1000000000000000000;
	d[0]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({0,0});
	while (pq.size()) {
		ll cd=pq.top().first; int cn=pq.top().second;
		pq.pop();
		if (d[cn] != cd) continue;
		for (auto i : adj[cn]) if (d[i.first] > cd+i.second) {
			d[i.first]=cd+i.second;
			pq.push({d[i.first],i.first});
		}
	}
	cout << d[2*n-1];
}