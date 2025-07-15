#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

vector<int> po;
int dt[MAXN];
bool v[MAXN];
vector<int> rev[MAXN];
bool ic[MAXN];

void dfs(int cn) {
	if (v[cn]) return;
	v[cn]=1;
	dfs(dt[cn]);
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

int bt[MAXN];

void ab(int cn) {
	if (v[cn]) return;
	v[cn]=1;
	if (ic[cn]) {
		bt[cn]=cn;
		return;
	}
	ab(dt[cn]);
	bt[cn]=bt[dt[cn]];
}

int ci[MAXN];
void si(int cn, int p) {
	if (v[cn]) return;
	v[cn]=1;
	ci[cn]=p;
	si(dt[cn],p+1);
}

int t;
int tin[MAXN],tout[MAXN],bd[MAXN];
void et(int cn, int d) {
	tin[cn]=t;
	bd[cn]=d;
	t++;
	for (int i : rev[cn]) et(i,d+1);
	tout[cn]=t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q; cin >> n >> q;
	for (int i=0; i<n; i++) {
		cin >> dt[i]; 
		dt[i]--;
		rev[dt[i]].push_back(i);
	}
	for (int i=0; i<n; i++) dfs(i);
	for (int i=0; i<n; i++) v[i]=0;
	for (int i=n-1; i>=0; i--) dfs2(po[i],po[i]);
	for (int i=0; i<n; i++) if (sz[g[i]]>1 || dt[i]==i) ic[i]=1;
	for (int i=0; i<n; i++) v[i]=0;
	for (int i=0; i<n; i++) ab(i);
	for (int i=0; i<n; i++) v[i]=0;
	for (int i=0; i<n; i++) if (g[i]==i) si(i,0);
	for (int i=0; i<n; i++) if (ic[dt[i]] && !ic[i]) et(i,1);
	while (q--) {
		int a,b; cin >> a >> b;
		a--; b--;
		if (ic[a] && !ic[b]) cout << -1 << '\n';
		else if (ic[a] && ic[b]) {
			if (g[a]==g[b]) {
				int d = ci[b]-ci[a];
				if (d<0) d += sz[g[a]];
				cout << d << '\n';
			}
			else cout << -1 << '\n';
		}
		else if (!ic[a] && !ic[b]) {
			if (tin[b]<=tin[a] && tin[a]<tout[b]) cout << bd[a]-bd[b] << '\n';
			else cout << -1 << '\n';
		}
		else {
			if (g[b]==g[bt[a]]) {
				int d = ci[b]-ci[bt[a]];
				if (d<0) d += sz[g[b]];
				cout << bd[a] + d << '\n';
			}
			else cout << -1 << '\n';
		}
	}
}