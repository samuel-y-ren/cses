#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	set<int> a[n+1];
	int e[n+1]; for (int i=1; i<=n; i++) e[i]=0;
	for (int i=0; i<m; i++) {
		int x,y; cin >> x >> y;
		a[x].insert(y);
		e[y]++;
	}
	for (int i=2; i<n; i++) if (a[i].size() != e[i]) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	if (a[1].size() != e[1]+1 || a[n].size()+1 != e[n])  {
		cout << "IMPOSSIBLE";
		return 0;
	}
	set<int> ne; 
	int c=1;
	vector<pair<int,int>> pl[n+1]; 
	while (a[c].size()) {
		ne.insert(c);
		int d = *a[c].begin();
		pl[c].push_back({d,pl[d].size()});
		a[c].erase(a[c].begin());
		if (!a[c].size()) ne.erase(c);
		c=d;
	}
	pl[c].push_back({-1,-1});
	ne.erase(c);

	while (ne.size()) {
		c = *ne.begin();
		pair<int,int> dt=pl[c][0];
		int d = *a[c].begin();
		pl[c][0]={d,pl[d].size()};
		a[c].erase(a[c].begin());
		if (!a[c].size()) ne.erase(c);
		c=d;
		while (a[c].size()) {
			ne.insert(c);
			d = *a[c].begin();
			pl[c].push_back({d,pl[d].size()});
			a[c].erase(a[c].begin());
			if (!a[c].size()) ne.erase(c);
			c=d;
		}
		ne.erase(c);
		pl[c].push_back(dt);
	}

	c=1; int x=0;
	for (int i=0; i<m; i++) {
		if (c==-1 && x==-1) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		pair<int,int> temp=pl[c][x];
		c=temp.first;x=temp.second;
	}
	c=1; x=0;
	while (m--) {
		cout << c << ' ';
		pair<int,int> temp=pl[c][x];
		c=temp.first; x=temp.second;
	}
	cout << n;
}