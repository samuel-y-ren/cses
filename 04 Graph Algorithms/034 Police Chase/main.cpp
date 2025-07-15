#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

const short MAXN=505;
short n;

short cap[MAXN][MAXN], flow[MAXN][MAXN];
short ht[MAXN], cv[MAXN];
short exc[MAXN];
queue<short> q;

vector<short> adj[MAXN]; 
short an[MAXN];

void ps(short u, short v) {
	short d = min((short)(cap[u][v]-flow[u][v]), exc[u]);
	if (!d) return;
	exc[u] -= d;
	exc[v] += d;
	flow[u][v] += d;
	flow[v][u] -= d;
	if (exc[v]==d) q.push(v);
}

void rl(short u) {
	short d = MAXN;
	for (short v : adj[u]) if (cap[u][v] > flow[u][v] && ht[v]<d) d = ht[v];
	if (d<MAXN) ht[u]=d+1;
}

void dc(short u) {
	while (exc[u]) {
		if (cv[u]<an[u]) {
			short v=adj[u][cv[u]];
			if (cap[u][v]>flow[u][v]&&ht[u]>ht[v]) ps(u,v);
			else cv[u]++;
		}
		else {
			rl(u);
			cv[u]=0;
		}
	}
}

bool vis[MAXN];
void dfs(short u) {
	if (vis[u]) return;
	vis[u]=1;
	for (short v : adj[u]) if (cap[u][v]>flow[u][v]) dfs(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	short m; cin >> n >> m;
	while (m--) {
		short a,b; cin >> a >> b;
		a--; b--;
		cap[a][b]++;
		cap[b][a]++;
	}
	for (short i=0; i<n; i++) {
		for (short j=0; j<n; j++) if (i != j && (cap[i][j] || cap[j][i])) adj[i].push_back(j);
		an[i]=adj[i].size();
	}
	exc[0]=10000;
	for (short i=1; i<n; i++) ps(0,i);
	ht[0]=n;
	while (q.size()) {
		short u = q.front();
		q.pop();
		if (u && u<n-1 && ht[u]<n) dc(u);
	}
	for (short i=0; i<n; i++) if (ht[i]>n) q.push(i);
	while (q.size()) {
		short u = q.front();
		q.pop();
		if (u && u<n-1 && ht[u]<n) dc(u);
	}
	short mf=0;
	for (short i=0; i<n-1; i++) mf+=flow[i][n-1];
	cout << mf << '\n';
	dfs(0);
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (vis[i] && !vis[j] && cap[i][j]) cout << i+1 << ' ' << j+1 << '\n';
}