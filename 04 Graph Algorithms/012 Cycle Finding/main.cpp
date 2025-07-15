#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool smin(ll &a, const ll b) {
	if (b<a) {
		a=b; return true;
	}
	return false;
}

vector<int> ad[2505];
bool v[2505];
int ip[2505];
bool f;
 
vector<int> p;
 
void dfs(int cn) {
	if (f) return;
	v[cn]=1;
	if (ip[cn]!=-1) {
		f=1;
		cout << "YES\n";
		for (int i=ip[cn]; i<p.size(); i++) cout << p[i]+1 << ' ';
		cout << cn+1 << '\n';
		return;
	}
	ip[cn]=p.size();
	p.push_back(cn);
	for (int i : ad[cn]) {
		dfs(i);
		if (f) return;
	}
	p.pop_back();
	ip[cn]=-1;
}


int main() {
	int n,m; cin >> n >> m;
	int a[m],b[m],c[m];
	for (int i=0; i<m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
	}

	ll d[n]; for (int i=0; i<n; i++) d[i]=0;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) smin(d[b[j]],d[a[j]]+c[j]);

	bool adj[n][n]; for (int i=0; i<n; i++) for (int j=0; j<n; j++) adj[i][j]=0;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) if(smin(d[b[j]],d[a[j]]+c[j])) adj[a[j]][b[j]]=1;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (adj[i][j]) ad[i].push_back(j);

	for (int i=0; i<n; i++) ip[i]=-1;
	for (int i=0; i<n; i++) if (!v[i]) dfs(i);
	if (!f) {
		cout << "NO\n";
		return 0;
	}

}