#include <bits/stdc++.h>
using namespace std;
 
const int MAXN=100005;
 
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
	int n,m; cin >> n >> m;
	int k[n]; for (int i=0; i<n; i++) cin >> k[i];
	for (int i=0; i<m; i++) {
		int a,b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	for (int i=0; i<n; i++) dfs(i);
	for (int i=0; i<n; i++) v[i]=0;
	for (int i=n-1; i>=0; i--) dfs2(po[i],po[i]);
	vector<int> ga[n];
	long long gk[n], dp[n]; 
	int ie[n]; 
	for (int i=0; i<n; i++) gk[i]=dp[i]=ie[i]=0;
	for (int i : co) for (int j : g[i]) {
		for (int k : adj[j]) if (i != mb[k]) {
			ga[i].push_back(mb[k]);
			ie[mb[k]]++;
		}
		gk[i]+=k[j];
	}
	vector<int> stk;
	for (int i : co) if (!ie[i]) stk.push_back(i);
	while (stk.size()) {
		int cn=stk.back();
		stk.pop_back();
		dp[cn] += gk[cn];
		for (int i : ga[cn]) {
			dp[i] = max(dp[i], dp[cn]);
			ie[i]--;
			if (!ie[i]) stk.push_back(i);
		}
	}
	cout << *max_element(dp,dp+n);
}