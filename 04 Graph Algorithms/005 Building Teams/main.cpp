#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int t[100005];
bool w=1;

void dfs(int x, short p) {
	if (t[x]==p) return;
	if (t[x]==3-p) {
		w=0;
		return;
	}
	t[x]=p;
	for (int i : adj[x]) dfs(i,3-p);
}

int main() {
	int n,m; cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	for (int i=1; i<=n; i++) if (!t[i]) dfs(i,1);
	if (w) {
		for (int i=1; i<=n; i++) cout << t[i] << ' ';
		cout << '\n';
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
}