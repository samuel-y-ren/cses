#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool v[100005];
int ip[100005];
bool f;

vector<int> p;

void dfs(int cn, int pn) {
	if (f) return;
	v[cn]=1;
	if (ip[cn]!=-1) {
		f=1;
		cout << p.size()-ip[cn]+1 << '\n';
		for (int i=ip[cn]; i<p.size(); i++) cout << p[i] << ' ';
		cout << cn << '\n';
		return;
	}
	ip[cn]=p.size();
	p.push_back(cn);
	for (int i : adj[cn]) {
		if (i!=pn) dfs(i,cn);
		if (f) return;
	}
	p.pop_back();
	ip[cn]=-1;
}

int main() {
	int n,m; cin >> n >> m;
	for (int i=0; i<=n; i++) ip[i]=-1;
	for (int i=0; i<m; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	for (int i=1; i<=n; i++) if (!v[i]) dfs(i,0);
	if (!f) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

}