#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize("Ofast")

const short MAXN=505;
short n;

ll cap[MAXN][MAXN], flow[MAXN][MAXN];
short ht[MAXN], cv[MAXN];
ll exc[MAXN];
queue<short> q;

vector<short> adj[MAXN]; 
short an[MAXN];

void ps(short u, short v) {
	ll d = min(cap[u][v]-flow[u][v], exc[u]);
	if (!d) return;
	exc[u] -= d;
	exc[v] += d;
	flow[u][v] += d;
	flow[v][u] -= d;
	if (exc[v]==d) q.push(v);
}

void rl(short u) {
	short d = MAXN*2;
	for (short v : adj[u]) if (cap[u][v] > flow[u][v] && ht[v]<d) d = ht[v];
	if (d<2*MAXN) ht[u]=d+1;
}

void dc(int u) {
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	short m; cin >> n >> m;
	while (m--) {
		int a,b,c; cin >> a >> b >> c;
		a--; b--;
		cap[a][b]+=c;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) if (i != j && (cap[i][j] || cap[j][i])) adj[i].push_back(j);
		an[i]=adj[i].size();
	}
	exc[0]=1000000000000000000;
	for (short i=1; i<n; i++) ps(0,i);
	ht[0]=n;
	while (q.size()) {
		short u = q.front();
		q.pop();
		if (u && u<n-1 && ht[u]<n) dc(u);
	}
	ll mf=0;
	for (short i=0; i<n-1; i++) mf+=flow[i][n-1];
	cout << mf;
}