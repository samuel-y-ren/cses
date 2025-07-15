#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

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
	vector<int> k; 
	for (int i=0; i<n; i++) if (i==g[i]) k.push_back(i);
	int kti[n];
	for (int i=0; i<k.size(); i++) kti[k[i]]=i+1;
	cout << k.size() << '\n';
	for (int i=0; i<n; i++) cout << kti[g[i]] << ' ';
}