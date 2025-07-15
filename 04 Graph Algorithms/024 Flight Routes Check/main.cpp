#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

vector<int> po;
vector<int> adj[MAXN];
bool v[MAXN];
vector<int> rev[MAXN];
bool ic[MAXN];

void dfs(int cn) {
	if (v[cn]) return;
	v[cn]=1;
	for (int i : adj[cn]) dfs(i);
	po.push_back(cn);
}

int g[MAXN];
int sz[MAXN];
void dfs2(int cn, int r) {
	if (v[cn]) return;
	v[cn]=1;
	g[cn]=r;
	sz[r]++;
	for (int i : rev[cn]) dfs2(i,r);
}

bool dfs3(int cn, int t) {
	if (v[cn]) return false;
	v[cn]=1;
	if (cn==t) return true;
	for (int i : adj[cn]) {
		if (dfs3(i,t)) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m; cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a,b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	for (int i=0; i<n; i++) dfs(i);
	for (int i=0; i<n; i++) v[i]=0;
	for (int i=n-1; i>=0; i--) dfs2(po[i],po[i]);
	for (int i=0; i<n; i++) v[i]=0;
	if (sz[g[0]]==n) cout << "YES\n";
	else {
		cout << "NO\n";
		for (int i=1; i<n; i++) if (g[i] != g[0]) {
			if (dfs3(0,i)) cout << i+1 << ' ' << 1 << '\n';
			else cout << 1 << ' ' << i+1 << '\n';
			break;
		}
	}
}