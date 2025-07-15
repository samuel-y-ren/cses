#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool v[100005];

void dfs(int c) {
	if (v[c]) return;
	v[c]=1;
	for (int i : adj[c]) dfs(i);
}

int main() {
	int n,m; cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> nd;
	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			nd.push_back(i);
			dfs(i);
		}
	}
	cout << nd.size()-1 << '\n'; 
	for (int i=1; i<nd.size(); i++) cout << nd[0] << ' ' << nd[i] << '\n';
}