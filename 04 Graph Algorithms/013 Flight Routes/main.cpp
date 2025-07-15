#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,m,k; cin >> n >> m >> k;
	vector<pair<int,int>> adj[n];
	for (int i=0; i<m; i++) {
		int a,b,c; cin >> a >> b >> c;
		adj[a-1].push_back({b-1,c}); 
	}
	vector<ll> d[n];
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({0,0}); d[0].push_back(0);
	while (pq.size()) {
		ll cd=pq.top().first; int cn=pq.top().second;
		pq.pop();
		if (binary_search(d[cn].begin(),d[cn].end(),cd)) {
			for (auto i : adj[cn]) {
				ll fd=cd+i.second;
				if (d[i.first].size()<k || d[i.first].back()>fd) {
					auto it = lower_bound(d[i.first].begin(),d[i.first].end(),fd);
					d[i.first].insert(it,fd);
					pq.push({fd,i.first});
					if (d[i.first].size()>k) d[i.first].pop_back();
				}
			}
		}
	}
	for (int i=0; i<k; i++) cout << d[n-1][i] << ' ';
}