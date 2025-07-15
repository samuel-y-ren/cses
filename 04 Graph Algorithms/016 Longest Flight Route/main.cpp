#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	vector<int> l[n+1]; int inc[n+1];
	vector<int> bk[n+1];
	for (int i=1; i<=n; i++) inc[i]=0;
	for (int i=0; i<m; i++) {
		int a,b; cin >> a >> b;
		l[a].push_back(b);
		bk[b].push_back(a);
		inc[b]++;
	}
	int d[n+1]; for (int i=1; i<=n; i++) d[i]=-1000000000;
	d[1]=1;
	vector<int> stk; 
	for (int i=1; i<=n; i++) if (!inc[i]) stk.push_back(i);
	while (stk.size()) {
		int cn=stk.back();
		stk.pop_back();
		for (int i : l[cn]) {
			d[i] = max(d[i],d[cn]+1);
			inc[i]--;
			if (!inc[i]) stk.push_back(i);
		}
	}
	if (d[n]<-500000000) cout << "IMPOSSIBLE\n";
	else {
		cout << d[n] << '\n';
		vector<int> path;
		int cn=n;
		path.push_back(n);
		for (int i=d[n]-1; i>0; i--) {
			for (int j : bk[cn]) if (d[j]==i) {
				path.push_back(j);
				cn=j;
				break;
			}
		}
		for (int i=d[n]-1; i>=0; i--) cout << path[i] << ' ';

	}
}