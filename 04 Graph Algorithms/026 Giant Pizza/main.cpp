#include <bits/stdc++.h>
using namespace std;
 
const int MAXN=200005;
 
vector<int> po;
vector<int> adj[MAXN];
bool v[MAXN];
vector<int> rev[MAXN];
 
void dfs(int cn) {
	if (v[cn]) return;
	v[cn]=1;
	for (int i : adj[cn]) dfs(i);
	po.push_back(cn);
}
 
int mb[MAXN];
vector<int> g[MAXN];
int sz[MAXN];
vector<int> co;
void dfs2(int cn, int r) {
	if (v[cn]) return;
	if (cn==r) co.push_back(cn);
	v[cn]=1;
	mb[cn]=r;
	g[r].push_back(cn);
	sz[r]++;
	for (int i : rev[cn]) dfs2(i,r);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m; cin >> m >> n;
	for (int i=0; i<m; i++) {
		char c1,c2; int t1,t2; cin >> c1 >> t1 >> c2 >> t2;
		t1--; t2--;
		bool f1=(c1=='+'),f2=(c2=='+');
		adj[t1+(!f1)*n].push_back(t2+f2*n);
		rev[t2+f2*n].push_back(t1+(!f1)*n);
		adj[t2+(!f2)*n].push_back(t1+f1*n);
		rev[t1+f1*n].push_back(t2+(!f2)*n);
	}
	for (int i=0; i<2*n; i++) dfs(i);
	for (int i=0; i<2*n; i++) v[i]=0;
	for (int i=2*n-1; i>=0; i--) dfs2(po[i],po[i]);	
	for (int i=0; i<n; i++) if (mb[i]==mb[n+i]) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	bool d[n], o[n]; for (int i=0; i<n; i++) d[i]=0;
	for (int i=co.size()-1; i>=0; i--) {
		bool w=0;
		for (int j : g[co[i]]) {
			if (d[j%n]) {
				w=1;
				break;
			}
		}
		if (w) continue;
		for (int j : g[co[i]]) {
			d[j%n]=1;
			o[j%n]=j/n;
		}
	}
	string ot[2]={"- ", "+ "};
	for (int i : o) cout << ot[i];
}