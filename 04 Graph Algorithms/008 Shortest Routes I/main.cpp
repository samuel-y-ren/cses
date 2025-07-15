#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,m; cin >> n >> m;
	vector<pair<int,int>> adj[n+1];
	for (int i=0; i<m; i++) {
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}
	ll d[n+1]; for (int i=0; i<=n; i++) d[i]=1000000000000000000;
	priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>>> pq;
	pq.push({0,1});
	d[1]=0;
	while (pq.size()) {
		ll cd = pq.top().first, cn=pq.top().second; 
		pq.pop();
		if (d[cn] != cd) continue;
		for (auto i : adj[cn]) {
			if (d[i.first] > cd+i.second) {
				d[i.first]=cd+i.second;
				pq.push({cd+i.second,i.first});
			}
		}
	}
	for (int i=1; i<=n; i++) cout << d[i] << ' ';
}